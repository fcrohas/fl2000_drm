/* SPDX-License-Identifier: GPL-2.0 */
/*
 * fl2000_streaming.c
 *
 * (C) Copyright 2017, Fresco Logic, Incorporated.
 * (C) Copyright 2018-2019, Artem Mygaiev
 */

#include "fl2000.h"

void fl2000_blank(struct drm_crtc *crtc);

/* Streaming is implemented with a single URB for each frame. USB is configured
 * to send NULL URB automatically after each data URB */
struct fl2000_stream {
	struct urb *urb;
};

static void fl2000_stream_completion(struct urb *urb)
{
	struct drm_crtc *crtc = urb->context;

	/* XXX: Maybe we need to check timings or lbuf? */

	fl2000_blank(crtc);
}

static void fl2000_stream_release(struct device *dev, void *res)
{
	/* Noop */
}

void fl2000_stream_frame(struct usb_device *usb_dev, dma_addr_t addr,
		struct drm_crtc *crtc)
{
	int ret = -1;
	struct fl2000_stream *stream = devres_find(&usb_dev->dev,
			fl2000_stream_release, NULL, NULL);

	if (stream) {
		struct urb *urb = stream->urb;
		urb->transfer_dma = addr;
		urb->context = crtc;
		ret = usb_submit_urb(urb, GFP_KERNEL);
	}

	if (ret) {
		/* TODO: schedule firing VBLANK immediately */
	}
}

int fl2000_stream_create(struct usb_interface *interface)
{
	int ret;
	struct fl2000_stream *stream;
	struct usb_device *usb_dev = interface_to_usbdev(interface);
	struct usb_endpoint_descriptor *desc = NULL;

	/* XXX: original driver uses default altsetting (#0) of streaming
	 * interface, which allows bursts of bulk transfers of 15x1024 bytes on
	 * output. It might be worth to try and switch to isochronous transfers
	 * on other altsetting, with similar or even better throughput. */
	ret = usb_find_bulk_out_endpoint(interface->cur_altsetting, &desc);
	if (ret)
		return ret;

	stream = devres_alloc(&fl2000_stream_release, sizeof(*stream),
			GFP_KERNEL);
	if (!stream) {
		dev_err(&usb_dev->dev, "Cannot allocate streaming private " \
				"structure");
		return -ENOMEM;
	}
	devres_add(&usb_dev->dev, stream);

	stream->urb = usb_alloc_urb(0, GFP_ATOMIC);
	if (!stream->urb) {
		dev_err(&usb_dev->dev, "Allocate stream FB URB failed");
		return -ENOMEM;
	}

	usb_fill_bulk_urb(stream->urb, usb_dev,
			usb_rcvintpipe(usb_dev, usb_endpoint_num(desc)),
			NULL, 0, fl2000_stream_completion, NULL);
	stream->urb->transfer_flags |=
			URB_ZERO_PACKET | 	 /* send NULL URB after data */
			URB_NO_TRANSFER_DMA_MAP; /* use urb->transfer_dma */

	usb_set_intfdata(interface, stream);

	return 0;
}

void fl2000_stream_destroy(struct usb_interface *interface)
{
	struct fl2000_stream *stream = usb_get_intfdata(interface);

	usb_poison_urb(stream->urb);

	usb_free_urb(stream->urb);
}

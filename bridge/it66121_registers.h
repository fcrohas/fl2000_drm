/* SPDX-License-Identifier: GPL-2.0 */
/*
 * it66121_registers.h
 *
 * Based on the un-official documentation found on the net and registers
 * description from source code:
 * 	- FL2000DX Linux driver on GitHub
 * 	- RK3188 Android driver on GitHub
 *
 * (C) Copyright 2019, Artem Mygaiev
 */

#ifndef __FL2000_REGISTERS_H__
#define __FL2000_REGISTERS_H__

#define IT66121_BANK_0_OFFSET		0x00

#define IT66121_VENDOR_ID_1		0x00
#define IT66121_VENDOR_ID_2		0x01
#define IT66121_DEVICE_ID_1		0x02
#define IT66121_DEVICE_ID_2		0x03
#define IT66121_SW_RESET		0x04
#define IT66121_INT_CONTROL		0x05
#define IT66121_INT_STATUS_1		0x06
#define IT66121_INT_STATUS_2		0x07
#define IT66121_INT_STATUS_3		0x08
#define IT66121_INT_MASK_1		0x09
#define IT66121_INT_MASK_2		0x0A
#define IT66121_INT_MASK_3		0x0B
#define IT66121_INT_CLEAR_1		0x0C
#define IT66121_INT_CLEAR_2		0x0D
#define IT66121_SYS_CONTROL_1		0x0E
#define IT66121_SYS_CONTROL_2		0x0F
#define IT66121_DDC_CONTROL		0x10
#define IT66121_DDC_ADDRESS		0x11
#define IT66121_DDC_OFFSET		0x12
#define IT66121_DDC_BYTE		0x13
#define IT66121_DDC_SEGMENT		0x14
#define IT66121_DDC_COMMAND		0x15
#define IT66121_DDC_STATUS		0x16
#define IT66121_DDC_RD_FIFO		0x17
/* reserved */
#define IT66121_HDCP_ADDRESS		0x19
/* reserved */
#define IT66121_DDC_BUS_HOLD_TIME	0x1B
#define IT66121_ROM_STATUS		0x1C
/* reserved */
/* reserved */
/* 1F - 57 HDCP registers, ignored */
#define IT66121_MCLK_CONTROL		0x58
#define IT66121_PLL_CONTROL		0x59
#define IT66121_CLK_POWER_CONTROL	0x5A
#define IT66121_OS_FREQ_NUM_2		0x5B
#define IT66121_OS_FREQ_NUM_1		0x5C
/* reserved */
#define IT66121_TX_CLK_COUNT		0x5E
#define IT66121_PLL_LOCK_STATUS		0x5F
#define IT66121_AUDIO_FREQ_COUNT	0x60
#define IT66121_AFE_DRV_CONTROL		0x61
#define IT66121_AFE_XP_CONTROL		0x62
#define IT66121_AFE_IP_CONTROL_2	0x63
#define IT66121_AFE_IP_CONTROL_1	0x64
#define IT66121_AFE_RING_CONTROL	0x65
#define IT66121_AFE_DRV_HS		0x66
/* reserved */
#define IT66121_AFE_IP_CONTROL_3	0x68
#define IT66121_AFE_PAT_RSTB		0x69
#define IT66121_AFE_XP_TEST		0x6A
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* reserved */
#define IT66121_INPUT_MODE		0x70
#define IT66121_INPUT_IO_CONTROL	0x71
#define IT66121_INPUT_COLOR_CONV	0x72
#define IT66121_Y_BLANK_LEVEL		0x73
#define IT66121_C_BLANK_LEVEL		0x74
#define IT66121_RGB_BLANK_LEVEL		0x75
#define IT66121_MATRIX_11V_1		0x76
#define IT66121_MATRIX_11V_2		0x77
#define IT66121_MATRIX_12V_1		0x78
#define IT66121_MATRIX_12V_2		0x79
#define IT66121_MATRIX_13V_1		0x7A
#define IT66121_MATRIX_13V_2		0x7B
#define IT66121_MATRIX_21V_1		0x7C
#define IT66121_MATRIX_21V_2		0x7D
#define IT66121_MATRIX_22V_1		0x7E
#define IT66121_MATRIX_22V_2		0x7F
#define IT66121_MATRIX_23V_1		0x80
#define IT66121_MATRIX_23V_2		0x81
#define IT66121_MATRIX_31V_1		0x82
#define IT66121_MATRIX_31V_2		0x83
#define IT66121_MATRIX_32V_1		0x84
#define IT66121_MATRIX_32V_2		0x85
#define IT66121_MATRIX_33V_1		0x86
#define IT66121_MATRIX_33V_2		0x87
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* reserved */
#define IT66121_PCI2C_CEC_ADDRESS	0x8D
/* reserved */
/* reserved */
/* 90 - BF Pattern generation registers, ignored */
#define IT66121_HDMI_MODE		0xC0
#define IT66121_HDMI_AV_MUTE		0xC1
#define IT66121_HDMI_BLACK_SRC		0xC2
#define IT66121_HDMI_OESS_PREIOD	0xC3
/* reserved */
#define IT66121_HDMI_AUDIO_CTS		0xC5
#define IT66121_HDMI_GEN_CTRL_PACKET	0xC6
/* reserved */
/* reserved */
#define IT66121_HDMI_NULL_PACKET	0xC9
#define IT66121_HDMI_ACP_PACKET		0xCA
/* reserved */
/* reserved */
#define IT66121_HDMI_AVI_INFO_PACKET	0xCD
#define IT66121_HDMI_AUDIO_INFO_PACKET	0xCE
/* reserved */
#define IT66121_HDMI_MPEG_INFO_PACKET	0xD0
#define IT66121_HDMI_VIDEO_PARAM_STATUS	0xD1
#define IT66121_HDMI_3D_INFO_PACKET	0xD2
/* reserved */
/* reserved */
/* reserved */
/* reserved */
#define IT66121_HDMI_PCLK_CONTROL	0xD7
#define IT66121_HDMI_PCLK_COUNT		0xD8
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* reserved */
/* E0 - F2 Audio channel registers, ignored */
/* F3 - F8 Test registers, ignored */

#define IT66121_BANK_1_OFFSET		0x01

/* 30 - 8F Packet content registers, ignored */
/* 90 - BF Audio channel status registers, ignored */

/*  CEC registers bank, ignored */

#endif /* __FL2000_REGISTERS_H__ */
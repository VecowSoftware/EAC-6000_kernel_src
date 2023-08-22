/*
 * ar0234_mode_tbls.h - ar0234 sensor mode tables
 *
 * Copyright (c) 2018-2022, NVIDIA CORPORATION.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __AR0234_I2C_TABLES__
#define __AR0234_I2C_TABLES__

#include <media/camera_common.h>

#define AR0234_TABLE_WAIT_MS	0xff00
#define AR0234_TABLE_END	0xff01
#define AR0234_MAX_RETRIES	3
#define AR0234_WAIT_MS_STOP	1
#define AR0234_WAIT_MS_START	30
#define AR0234_WAIT_MS_STREAM	210
#define AR0234_GAIN_TABLE_SIZE 255

#define AR0234_EEPROM_ADDRESS		0x38
#define AR0234_EEPROM_ADDRESS_R         0x58
#define AR0234_EEPROM_SIZE              512
#define AR0234_EEPROM_STR_SIZE          (AR0234_EEPROM_SIZE * 2)
#define AR0234_EEPROM_BLOCK_SIZE        (1 << 8)
#define AR0234_EEPROM_NUM_BLOCKS \
	(AR0234_EEPROM_SIZE / AR0234_EEPROM_BLOCK_SIZE)


#define ar0234_reg struct reg_16

struct index_reg_8 {
	u16 source;
	u16 addr;
	u16 val;
};

static struct index_reg_8 ar0234_start[] = {
	{0x06,0x30ce, 0x0120},
	{0x06,0x301A, 0x295C}, // RESET_REGISTER
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 ar0234_stop[] = {
	{0x06,0x301a, 0x2058},
	{0x00,AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 i2c_address_trans_hawk_ser[] = {
	{0x52, 0x0006, 0x11},
	{0x80, 0x0000, 0x94},
	{0x52, 0x0006, 0x33},
	{0x80, 0x0000, 0x96},
	{0x00, AR0234_TABLE_END, 0x00}
};

/* Deser/Ser I2C address translation */
static struct index_reg_8 i2c_address_trans_hawk[] = {
	/* HWAK1 0x10 -> 0x30, 0x18 -> 0x31 */
	{0x94, 0x0042, 0x60},
	{0x94, 0x0043, 0x20},
	{0x94, 0x0044, 0x62},
	{0x94, 0x0045, 0x30},
	/* HWAK2 0x10 -> 0x32 0x18 -> 0x33 */
	{0x96, 0x0042, 0x64},
	{0x96, 0x0043, 0x20},
	{0x96, 0x0044, 0x66},
	{0x96, 0x0045, 0x30},
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 i2c_address_trans_hawk_eeprom[] = {
	{0x94, 0x0042, 0x80},
	{0x94, 0x0043, 0xA8},
	{0x94, 0x0044, 0x82},
	{0x94, 0x0045, 0xAA},
	{0x96, 0x0042, 0x84},
	{0x96, 0x0043, 0xA8},
	{0x96, 0x0044, 0x86},
	{0x96, 0x0045, 0xAA},
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 i2c_address_trans_owl_ser[] = {
	{0x52, 0x0006, 0x11},
	{0x80, 0x0000, 0x94},
	{0x52, 0x0006, 0x33},
	{0x80, 0x0000, 0x96},
	{0x52, 0x0006, 0x77},
	{0x80, 0x0000, 0x98},
	{0x52, 0x0006, 0xff},
	{0x80, 0x0000, 0x9a},
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 i2c_address_trans_owl[] = {
	/* OWL A 0x18 -> 0x30 0x43 -> 0x31 */
	{0x94, 0x02be, 0x1d},
	{0x94, 0x0042, 0x60},
	{0x94, 0x0043, 0x30},
	{0x94, 0x0044, 0x62},
	{0x94, 0x0045, 0x86},

	/* OWL B 0x18 -> 0x32, 0x43 - > 0x33*/
	{0x96, 0x0042, 0x64},
	{0x96, 0x0043, 0x30},
	{0x96, 0x0044, 0x66},
	{0x96, 0x0045, 0x86},

	/* OWL C 0x18 -> 0x34, 0x43 -> 0x35 */
	{0x98, 0x0042, 0x68},
	{0x98, 0x0043, 0x30},
	{0x98, 0x0044, 0x6a},
	{0x98, 0x0045, 0x86},
	/* OWL D 0x18 -> 0x36, 0x43 -> 0x37 */
	{0x9a, 0x0042, 0x6c},
	{0x9a, 0x0043, 0x30},
	{0x9a, 0x0044, 0x6e},
	{0x9a, 0x0045, 0x86},
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 i2c_address_trans_owl_eeprom[] = {
	{0x94, 0x0042, 0x70},
	{0x94, 0x0043, 0xA8},
	{0x94, 0x0044, 0x72},
	{0x94, 0x0045, 0xAA},
	{0x96, 0x0042, 0x74},
	{0x96, 0x0043, 0xA8},
	{0x96, 0x0044, 0x76},
	{0x96, 0x0045, 0xAA},
	{0x98, 0x0042, 0x78},
	{0x98, 0x0043, 0xA8},
	{0x98, 0x0044, 0x7A},
	{0x98, 0x0045, 0xAA},
	{0x9a, 0x0042, 0x7C},
	{0x9a, 0x0043, 0xA8},
	{0x9a, 0x0044, 0x7E},
	{0x9a, 0x0045, 0xAA},
	{0x00, AR0234_TABLE_END, 0x00}
};

static struct index_reg_8 ar0234_Hawk_Dser_Ser[] = {
	{0x52, 0x1458, 0x28},
	{0x52, 0x1459, 0x68},
	{0x52, 0x1558, 0x28},
	{0x52, 0x1559, 0x68},
	{0x52, 0x1658, 0x28},
	{0x52, 0x1659, 0x68},
	{0x52, 0x1758, 0x28},
	{0x52, 0x1759, 0x68},

	{0x52, 0x0018, 0x0F}, // Oneshot reset
	{0x52, 0x0006, 0xF3}, // Enable links A and B


	{0x94, 0x0002, 0x33}, // Enable pipes X and Y
	{0x94, 0x0308, 0x7E}, // Pipe X pulls clock from port A, pipe Y from port B
	{0x94, 0x0311, 0x21}, // Pipe X pulls data from port A, pipe Y from port B
	{0x94, 0x0316, 0x6b}, // RAW10 to pipe Y
	{0x94, 0x0314, 0x6b}, // RAW10 to pipe Y
	{0x96, 0x0002, 0x33}, // Enable pipes X and Y
	{0x96, 0x0308, 0x7E}, // Pipe X pulls clock from port A, pipe Y from port B
	{0x96, 0x0311, 0x21}, // Pipe X pulls data from port A, pipe Y from port B
	{0x96, 0x0316, 0x6b}, // RAW10 to pipe Y
	{0x96, 0x0314, 0x6b}, // RAW10 to pipe Y
	{0x52, 0x00F4, 0x0f}, // Enable pipe 0

	/*Tuned params to fix streaming issues */
	{0x52, 0x00F0, 0x01}, // Link A ID 0 to pipe 0 // Link A ID 1 to pipe 1
	{0x52, 0x00F1, 0x45}, // Link B ID 0 to pipe 2  // Link B ID 1 to pipe 3

	{0x52, 0x08A0, 0x01}, // CSI output is 2x4
	{0x52, 0x08A3, 0x44}, // Default 4x2 lane mapping
	{0x52, 0x08A4, 0x44}, // Default 4x2 lane mapping

	{0x52, 0x090A, 0x40},
	{0x52, 0x094A, 0x40}, // 2 lanes on port D
	{0x52, 0x098A, 0x40}, // 2 lanes on port E
	{0x52, 0x09CA, 0x40},

	{0x52, 0x1D00, 0xF4},
	{0x52, 0x1E00, 0xF4},

	{0x52, 0x0415, 0x39},
	{0x52, 0x0418, 0x39},	// 2500Mbps/lane on port D
	{0x52, 0x041B, 0x39},	// 2500Mbps/lane on port E
	{0x52, 0x041E, 0x39},

	{0x52, 0x1D00, 0xF5},
	{0x52, 0x1E00, 0xF5},

	{0x52, 0x090B, 0x07}, // Enable 3 mappings  Pipe 0//video2
	{0x52, 0x092D, 0x00}, 	// All mappings to controller 1 (port A)
	{0x52, 0x090D, 0x2B}, // Input RAW10, VC0
	{0x52, 0x090E, 0x2B}, // Output RAW10, VC0
	{0x52, 0x090F, 0x00}, // Input FS, VC0
	{0x52, 0x0910, 0x00}, // Output FS, VC0
	{0x52, 0x0911, 0x01}, // Input FE, VC0
	{0x52, 0x0912, 0x01}, // Output FE, VC0

	{0x52, 0x094B, 0x07}, // Enable 3 mappings  Pipe 1  //video3
	{0x52, 0x096D, 0x00}, 	// All mappings to controller 1 (port A)
	{0x52, 0x094D, 0x2B}, // Input RAW10, VC0
	{0x52, 0x094E, 0x6B}, // Output RAW10, VC1
	{0x52, 0x094F, 0x00}, // Input FS, VC0
	{0x52, 0x0950, 0x40}, // Output FS, VC1
	{0x52, 0x0951, 0x01}, // Input FE, VC0
	{0x52, 0x0952, 0x41}, // Output FE, VC1

	{0x52, 0x098B,0x07}, // Enable 3 mappings Pipe 2  //video1
	{0x52, 0x09AD,0x15}, // All mappings to controller 1 (port A)
	{0x52, 0x098D,0x2B}, 	// Input RAW10, VC0
	{0x52, 0x098E,0x2B}, 	// Output RAW10, VC0
	{0x52, 0x098F,0x00}, 	// Input FS, VC0
	{0x52, 0x0990,0x00},	// Output FS, VC0
	{0x52, 0x0991,0x01}, 	// Input FE, VC0
	{0x52, 0x0992,0x01}, 	// Output FE, VC0

	{0x52, 0x09CB,0x07}, // Enable 3 mappings  Pipe 3  //video0
	{0x52, 0x09ED,0x15}, // All mappings to controller 1 (port A)
	{0x52, 0x09CD,0x2B}, 	// Input RAW10, VC0
	{0x52, 0x09CE,0x6B}, 	// Output RAW10, VC1
	{0x52, 0x09CF,0x00}, 	// Input FS, VC0
	{0x52, 0x09D0,0x40},	// Output FS, VC1
	{0x52, 0x09D1,0x01}, 	// Input FE, VC0
	{0x52, 0x09D2,0x41}, 	// Output FE, VC1
	{0x52, 0x08A2,0xF0},
	{0x94, 0x02be,0x90}, // Enable sensor power down pin.
	{0x94, 0x02bf,0x60}, // Enable sensor reset pin.
	{0x94, 0x02ca,0x80}, // Enable sensor power down pin.
	{0x94, 0x02cb,0x60}, // Enable sensor reset pin.
	{0x94, 0x02d3,0x90}, // Enable sensor power down pin.
	{0x94, 0x02d4,0x60}, // Enable sensor reset pin.
	{0x94, 0x02d6,0x90}, // Enable sensor power down pin.
	{0x94, 0x02d7,0x60}, // Enable sensor reset pin.
	{0x96, 0x02be,0x90}, // Enable sensor power down pin.
	{0x96, 0x02bf,0x60}, // Enable sensor reset pin.
	{0x96, 0x02ca,0x80}, // Enable sensor power down pin.
	{0x96, 0x02cb,0x60}, // Enable sensor reset pin.
	{0x96, 0x02d3,0x90}, // Enable sensor power down pin.
	{0x96, 0x02d4,0x60}, // Enable sensor reset pin.
	{0x96, 0x02d6,0x90}, // Enable sensor power down pin.
	{0x96, 0x02d7,0x60}, // Enable sensor reset pin.

	{0x00,AR0234_TABLE_END,0x00}
};

static struct index_reg_8 ar0234_Owl_Dser_Ser[] = {
	{0x52,0x1458,0x28},
	{0x52,0x1459,0x68},
	{0x52,0x1558,0x28},
	{0x52,0x1559,0x68},
	{0x52,0x1658,0x28},
	{0x52,0x1659,0x68},
	{0x52,0x1758,0x28},
	{0x52,0x1759,0x68},

	{0x94,0x0010,0x21},
	{0x96,0x0010,0x21},
	{0x98,0x0010,0x21},
	{0x9A,0x0010,0x21},
	{0x52,0x0006,0xFf},	// Enable links A, B, C, D
	/* OWL 1*/
	{0x94,0x02be,0x1d},
	{0x94,0x0311,0x20},
	{0x94,0x0308,0x62},
	{0x94,0x0316,0x6b},
	{0x94,0x0002,0x23},
	/* OWL 2*/
	{0x96,0x0311,0x20},
	{0x96,0x0308,0x62},
	{0x96,0x0316,0x6b},
	{0x96,0x0002,0x23},
	/* OWL 3*/
	{0x98,0x0311,0x20},
	{0x98,0x0308,0x62},
	{0x98,0x0316,0x6b},
	{0x98,0x0002,0x23},
	/* OWL 4*/
	{0x9A,0x0311,0x20},
	{0x9A,0x0308,0x62},
	{0x9A,0x0316,0x6b},
	{0x9A,0x0002,0x23},

	{0x52,0x00F4,0x0f},	// Enable pipe 0 -3
	{0x52,0x00F0,0x51},	// Link A ID 1 to pipe 0 // Link B ID 1 to pipe 1
	{0x52,0x00F1,0xD9}, // Link c ID 1 to pipe 2  // Link D ID 1 to pipe 3

	{0x52,0x08A0,0x01},	// CSI output is 2x4
	{0x52,0x08A3,0x44},	// Default 4x2 lane mapping
	{0x52,0x08A4,0x44},	// Default 4x2 lane mapping

	{0x52,0x090A,0x40},
	{0x52,0x094A,0x40},	// 2 lanes on port D
	{0x52,0x098A,0x40},	// 2 lanes on port E
	{0x52,0x09CA,0x40},

	{0x52,0x1D00,0xF4},
	{0x52,0x1E00,0xF4},

	{0x52,0x0415,0x39},
	{0x52,0x0418,0x39},	// 1500Mbps/lane on port D
	{0x52,0x041B,0x39},	// 1500Mbps/lane on port E
	{0x52,0x041E,0x39},

	{0x52,0x1D00,0xF5},
	{0x52,0x1E00,0xF5},
	{0x52,0x090B,0x07}, 	// Enable 3 mappings  Pipe 0//video2
	{0x52, 0x092D, 0x00},	// All mappings to controller 0 (port A)
	{0x52,0x090D,0x2B}, 	// Input RAW10, VC0
	{0x52,0x090E,0x2B}, 	// Output RAW10, VC0
	{0x52,0x090F,0x00}, 	// Input FS, VC0
	{0x52,0x0910,0x00},	// Output FS, VC0
	{0x52,0x0911,0x01}, 	// Input FE, VC0
	{0x52,0x0912,0x01}, 	// Output FE, VC0

	{0x52,0x094B,0x07}, 	// Enable 3 mappings  Pipe 1  //video3
	{0x52, 0x096D, 0x00},	// All mappings to controller 0 (port A)
	{0x52,0x094D,0x2B}, 	// Input RAW10, VC0
	{0x52,0x094E,0x6B}, 	// Output RAW10, VC1
	{0x52,0x094F,0x00}, 	// Input FS, VC0
	{0x52,0x0950,0x40},	// Output FS, VC1
	{0x52,0x0951,0x01}, 	// Input FE, VC0
	{0x52,0x0952,0x41}, 	// Output FE, VC1

	{0x52,0x098B,0x07}, 	// Enable 3 mappings Pipe 2  //video1
	{0x52, 0x09AD, 0x00},	// All mappings to controller 0 (port A)
	{0x52,0x098D,0x2B}, 	// Input RAW10, VC0
	{0x52,0x098E,0xaB}, 	// Output RAW10, VC2
	{0x52,0x098F,0x00}, 	// Input FS, VC0
	{0x52,0x0990,0x80},	// Output FS, VC2
	{0x52,0x0991,0x01}, 	// Input FE, VC0
	{0x52,0x0992,0x81}, 	// Output FE, VC2

	{0x52,0x09CB,0x07}, 	// Enable 3 mappings  Pipe 3  //video0
	{0x52, 0x09ED, 0x00},	// All mappings to controller 0 (port A)
	{0x52,0x09CD,0x2B}, 	// Input RAW10, VC0
	{0x52,0x09CE,0xeB}, 	// Output RAW10, VC3
	{0x52,0x09CF,0x00}, 	// Input FS, VC0
	{0x52,0x09D0,0xc0},	// Output FS, VC3
	{0x52,0x09D1,0x01}, 	// Input FE, VC0
	{0x52,0x09D2,0xc1}, 	// Output FE, VC3
	{0x52,0x08A2,0xF0},

	{0x94,0x02be,0x90}, // Enable sensor power down pin. Put imager in ,Active mode
	{0x94,0x02ca,0x80}, // Enable sensor power down pin.
	{0x94,0x02cb,0x60}, // Enable sensor reset pin.
	{0x94,0x03F1,0x00},

	{0x96,0x02be,0x90}, // Enable sensor power down pin. Put imager in ,Active mode
	{0x96,0x02ca,0x80}, // Enable sensor power down pin.
	{0x96,0x02cb,0x60}, // Enable sensor reset pin.
	{0x96,0x03F1,0x00},

	{0x98,0x02be,0x90}, // Enable sensor power down pin. Put imager in ,Active mode
	{0x98,0x02ca,0x80}, // Enable sensor power down pin.
	{0x98,0x02cb,0x60}, // Enable sensor reset pin.
	{0x98,0x03F1,0x00},

	{0x9A,0x02be,0x90}, // Enable sensor power down pin. Put imager in ,Active mode
	{0x9A,0x02ca,0x80}, // Enable sensor power down pin.
	{0x9A,0x02cb,0x60}, // Enable sensor reset pin.
	{0x9A,0x03F1,0x00},

	{0x00, AR0234_TABLE_END, 0x00 }
};


static struct index_reg_8 ar0234_1920x1080_crop_30fps[] = {
	{0x06, 0x301A, 0x00D9},
	{0x06, AR0234_TABLE_WAIT_MS, 100},

	{0x06, 0x3F4C, 0x121F},
	{0x06, 0x3F4E, 0x121F},
	{0x06, 0x3F50, 0x0B81},
	{0x06, 0x31E0, 0x0003},
	{0x06, 0x31E0, 0x0003},
	{0x06, 0x30B0, 0x0028},
	{0x06, 0x3088, 0x8000},
	{0x06, 0x3086, 0xC1AE},
	{0x06, 0x3086, 0x327F},
	{0x06, 0x3086, 0x5780},
	{0x06, 0x3086, 0x272F},
	{0x06, 0x3086, 0x7416},
	{0x06, 0x3086, 0x7E13},
	{0x06, 0x3086, 0x8000},
	{0x06, 0x3086, 0x307E},
	{0x06, 0x3086, 0xFF80},
	{0x06, 0x3086, 0x20C3},
	{0x06, 0x3086, 0xB00E},
	{0x06, 0x3086, 0x8190},
	{0x06, 0x3086, 0x1643},
	{0x06, 0x3086, 0x1651},
	{0x06, 0x3086, 0x9D3E},
	{0x06, 0x3086, 0x9545},
	{0x06, 0x3086, 0x2209},
	{0x06, 0x3086, 0x3781},
	{0x06, 0x3086, 0x9016},
	{0x06, 0x3086, 0x4316},
	{0x06, 0x3086, 0x7F90},
	{0x06, 0x3086, 0x8000},
	{0x06, 0x3086, 0x387F},
	{0x06, 0x3086, 0x1380},
	{0x06, 0x3086, 0x233B},
	{0x06, 0x3086, 0x7F93},
	{0x06, 0x3086, 0x4502},
	{0x06, 0x3086, 0x8000},
	{0x06, 0x3086, 0x7FB0},
	{0x06, 0x3086, 0x8D66},
	{0x06, 0x3086, 0x7F90},
	{0x06, 0x3086, 0x8192},
	{0x06, 0x3086, 0x3C16},
	{0x06, 0x3086, 0x357F},
	{0x06, 0x3086, 0x9345},
	{0x06, 0x3086, 0x0280},
	{0x06, 0x3086, 0x007F},
	{0x06, 0x3086, 0xB08D},
	{0x06, 0x3086, 0x667F},
	{0x06, 0x3086, 0x9081},
	{0x06, 0x3086, 0x8237},
	{0x06, 0x3086, 0x4502},
	{0x06, 0x3086, 0x3681},
	{0x06, 0x3086, 0x8044},
	{0x06, 0x3086, 0x1631},
	{0x06, 0x3086, 0x4374},
	{0x06, 0x3086, 0x1678},
	{0x06, 0x3086, 0x7B7D},
	{0x06, 0x3086, 0x4502},
	{0x06, 0x3086, 0x450A},
	{0x06, 0x3086, 0x7E12},
	{0x06, 0x3086, 0x8180},
	{0x06, 0x3086, 0x377F},
	{0x06, 0x3086, 0x1045},
	{0x06, 0x3086, 0x0A0E},
	{0x06, 0x3086, 0x7FD4},
	{0x06, 0x3086, 0x8024},
	{0x06, 0x3086, 0x0E82},
	{0x06, 0x3086, 0x9CC2},
	{0x06, 0x3086, 0xAFA8},
	{0x06, 0x3086, 0xAA03},
	{0x06, 0x3086, 0x430D},
	{0x06, 0x3086, 0x2D46},
	{0x06, 0x3086, 0x4316},
	{0x06, 0x3086, 0x5F16},
	{0x06, 0x3086, 0x530D},
	{0x06, 0x3086, 0x1660},
	{0x06, 0x3086, 0x401E},
	{0x06, 0x3086, 0x2904},
	{0x06, 0x3086, 0x2984},
	{0x06, 0x3086, 0x81E7},
	{0x06, 0x3086, 0x816F},
	{0x06, 0x3086, 0x1706},
	{0x06, 0x3086, 0x81E7},
	{0x06, 0x3086, 0x7F81},
	{0x06, 0x3086, 0x5C0D},
	{0x06, 0x3086, 0x5754},
	{0x06, 0x3086, 0x495F},
	{0x06, 0x3086, 0x5305},
	{0x06, 0x3086, 0x5307},
	{0x06, 0x3086, 0x4D2B},
	{0x06, 0x3086, 0xF810},
	{0x06, 0x3086, 0x164C},
	{0x06, 0x3086, 0x0755},
	{0x06, 0x3086, 0x562B},
	{0x06, 0x3086, 0xB82B},
	{0x06, 0x3086, 0x984E},
	{0x06, 0x3086, 0x1129},
	{0x06, 0x3086, 0x9460},
	{0x06, 0x3086, 0x5C09},
	{0x06, 0x3086, 0x5C1B},
	{0x06, 0x3086, 0x4002},
	{0x06, 0x3086, 0x4500},
	{0x06, 0x3086, 0x4580},
	{0x06, 0x3086, 0x29B6},
	{0x06, 0x3086, 0x7F80},
	{0x06, 0x3086, 0x4004},
	{0x06, 0x3086, 0x7F88},
	{0x06, 0x3086, 0x4109},
	{0x06, 0x3086, 0x5C0B},
	{0x06, 0x3086, 0x29B2},
	{0x06, 0x3086, 0x4115},
	{0x06, 0x3086, 0x5C03},
	{0x06, 0x3086, 0x4105},
	{0x06, 0x3086, 0x5F2B},
	{0x06, 0x3086, 0x902B},
	{0x06, 0x3086, 0x8081},
	{0x06, 0x3086, 0x6F40},
	{0x06, 0x3086, 0x1041},
	{0x06, 0x3086, 0x0160},
	{0x06, 0x3086, 0x29A2},
	{0x06, 0x3086, 0x29A3},
	{0x06, 0x3086, 0x5F4D},
	{0x06, 0x3086, 0x1C17},
	{0x06, 0x3086, 0x0281},
	{0x06, 0x3086, 0xE729},
	{0x06, 0x3086, 0x8345},
	{0x06, 0x3086, 0x8840},
	{0x06, 0x3086, 0x0F7F},
	{0x06, 0x3086, 0x8A40},
	{0x06, 0x3086, 0x2345},
	{0x06, 0x3086, 0x8024},
	{0x06, 0x3086, 0x4008},
	{0x06, 0x3086, 0x7F88},
	{0x06, 0x3086, 0x5D29},
	{0x06, 0x3086, 0x9288},
	{0x06, 0x3086, 0x102B},
	{0x06, 0x3086, 0x0489},
	{0x06, 0x3086, 0x165C},
	{0x06, 0x3086, 0x4386},
	{0x06, 0x3086, 0x170B},
	{0x06, 0x3086, 0x5C03},
	{0x06, 0x3086, 0x8A48},
	{0x06, 0x3086, 0x4D4E},
	{0x06, 0x3086, 0x2B80},
	{0x06, 0x3086, 0x4C09},
	{0x06, 0x3086, 0x4119},
	{0x06, 0x3086, 0x816F},
	{0x06, 0x3086, 0x4110},
	{0x06, 0x3086, 0x4001},
	{0x06, 0x3086, 0x6029},
	{0x06, 0x3086, 0x8229},
	{0x06, 0x3086, 0x8329},
	{0x06, 0x3086, 0x435C},
	{0x06, 0x3086, 0x055F},
	{0x06, 0x3086, 0x4D1C},
	{0x06, 0x3086, 0x81E7},
	{0x06, 0x3086, 0x4502},
	{0x06, 0x3086, 0x8180},
	{0x06, 0x3086, 0x7F80},
	{0x06, 0x3086, 0x410A},
	{0x06, 0x3086, 0x9144},
	{0x06, 0x3086, 0x1609},
	{0x06, 0x3086, 0x2FC3},
	{0x06, 0x3086, 0xB130},
	{0x06, 0x3086, 0xC3B1},
	{0x06, 0x3086, 0x0343},
	{0x06, 0x3086, 0x164A},
	{0x06, 0x3086, 0x0A43},
	{0x06, 0x3086, 0x160B},
	{0x06, 0x3086, 0x4316},
	{0x06, 0x3086, 0x8F43},
	{0x06, 0x3086, 0x1690},
	{0x06, 0x3086, 0x4316},
	{0x06, 0x3086, 0x7F81},
	{0x06, 0x3086, 0x450A},
	{0x06, 0x3086, 0x410F},
	{0x06, 0x3086, 0x7F83},
	{0x06, 0x3086, 0x5D29},
	{0x06, 0x3086, 0x4488},
	{0x06, 0x3086, 0x102B},
	{0x06, 0x3086, 0x0453},
	{0x06, 0x3086, 0x0D40},
	{0x06, 0x3086, 0x2345},
	{0x06, 0x3086, 0x0240},
	{0x06, 0x3086, 0x087F},
	{0x06, 0x3086, 0x8053},
	{0x06, 0x3086, 0x0D89},
	{0x06, 0x3086, 0x165C},
	{0x06, 0x3086, 0x4586},
	{0x06, 0x3086, 0x170B},
	{0x06, 0x3086, 0x5C05},
	{0x06, 0x3086, 0x8A60},
	{0x06, 0x3086, 0x4B91},
	{0x06, 0x3086, 0x4416},
	{0x06, 0x3086, 0x09C1},
	{0x06, 0x3086, 0x2CA9},
	{0x06, 0x3086, 0xAB30},
	{0x06, 0x3086, 0x51B3},
	{0x06, 0x3086, 0x3D5A},
	{0x06, 0x3086, 0x7E3D},
	{0x06, 0x3086, 0x7E19},
	{0x06, 0x3086, 0x8000},
	{0x06, 0x3086, 0x8B1F},
	{0x06, 0x3086, 0x2A1F},
	{0x06, 0x3086, 0x83A2},
	{0x06, 0x3086, 0x7516},
	{0x06, 0x3086, 0xAD33},
	{0x06, 0x3086, 0x450A},
	{0x06, 0x3086, 0x7F53},
	{0x06, 0x3086, 0x8023},
	{0x06, 0x3086, 0x8C66},
	{0x06, 0x3086, 0x7F13},
	{0x06, 0x3086, 0x8184},
	{0x06, 0x3086, 0x1481},
	{0x06, 0x3086, 0x8031},
	{0x06, 0x3086, 0x3D64},
	{0x06, 0x3086, 0x452A},
	{0x06, 0x3086, 0x9451},
	{0x06, 0x3086, 0x9E96},
	{0x06, 0x3086, 0x3D2B},
	{0x06, 0x3086, 0x3D1B},
	{0x06, 0x3086, 0x529F},
	{0x06, 0x3086, 0x0E3D},
	{0x06, 0x3086, 0x083D},
	{0x06, 0x3086, 0x167E},
	{0x06, 0x3086, 0x307E},
	{0x06, 0x3086, 0x1175},
	{0x06, 0x3086, 0x163E},
	{0x06, 0x3086, 0x970E},
	{0x06, 0x3086, 0x82B2},
	{0x06, 0x3086, 0x3D7F},
	{0x06, 0x3086, 0xAC3E},
	{0x06, 0x3086, 0x4502},
	{0x06, 0x3086, 0x7E11},
	{0x06, 0x3086, 0x7FD0},
	{0x06, 0x3086, 0x8000},
	{0x06, 0x3086, 0x8C66},
	{0x06, 0x3086, 0x7F90},
	{0x06, 0x3086, 0x8194},
	{0x06, 0x3086, 0x3F44},
	{0x06, 0x3086, 0x1681},
	{0x06, 0x3086, 0x8416},
	{0x06, 0x3086, 0x2C2C},
	{0x06, 0x3086, 0x2C2C},
	{0x06, 0x302A, 0x0005},
	{0x06, 0x302C, 0x0001},
	{0x06, 0x302E, 0x0003},
	{0x06, 0x3030, 0x0096}, // PLL multiplier
	{0x06, 0x302E, 0x0006}, // PLL input pre-divider value
	{0x06, 0x302C, 0x0004}, // P1 divider
	{0x06, 0x302A, 0x0005}, // P2 divider
	{0x06, 0x3038, 0x0004}, // P3 divider
	{0x06, 0x3036, 0x000A}, // WCD divider
	{0x06, 0x31B0, 0x002F}, // Frame preamble
	{0x06, 0x31B2, 0x002C}, // Line preamble
	{0x06, 0x31B4, 0x1144}, // MIPI timing 0
	{0x06, 0x31B6, 0x00C7}, // MIPI timing 1
	{0x06, 0x31B8, 0x3047}, // MIPI timing 2
	{0x06, 0x31BA, 0x0103}, // MIPI timing 3
	{0x06, 0x31BC, 0x8583}, // MIPI timing 4
	{0x06, 0x31AE, 0x0204}, // 4-lane MIPI
	{0x06, 0x3002, 0x0008}, // Y_ADDR_START = 8
	{0x06, 0x3004, 0x0008}, // X_ADDR_START = 8
	{0x06, 0x3006, 0x04B7}, // Y_ADDR_END = 1207
	{0x06, 0x3008, 0x0787}, // X_ADDR_END = 1927
        //{0x06, 0x300A, 0x04C6}, // FRAME_LENGTH_LINES = 1220
        //{0x06, 0x300C, 0x0264}, // LINE_LENGTH_PCK = 612
	{0x06, 0x300A, 0x04DD}, // FRAME_LENGTH_LINES = 1220
	{0x06, 0x300C, 0x0384}, // LINE_LENGTH_PCK = 612
	{0x06, 0x3012, 0x02DC}, // COARSE_INTEGRATION_TIME = 732
	{0x06, 0x31AC, 0x0A0A}, // DATA_FORMAT_BITS = 2570
	{0x06, 0x306E, 0x9010}, // DATAPATH_SELECT = 36880
	{0x06, 0x30A2, 0x0001}, // X_ODD_INC = 1
	{0x06, 0x30A6, 0x0001}, // Y_ODD_INC = 1
	{0x06, 0x3082, 0x0003}, // OPERATION_MODE_CTRL = 3
	{0x06, 0x3040, 0x0000}, // READ_MODE = 0
	{0x06, 0x31D0, 0x0000}, // COMPANDING = 0

	{0x06, 0x3044, 0x0410},
	{0x06, 0x3094, 0x03D4},
	{0x06, 0x3096, 0x0480},
	{0x06, 0x30BA, 0x7602},
	{0x06, 0x30B0, 0x0028},
	{0x06, 0x30FE, 0x002A},
	{0x06, 0x31DE, 0x0410},
	{0x06, 0x3ED6, 0x1435},
	{0x06, 0x3ED8, 0x9865},
	{0x06, 0x3EDA, 0x7698},
	{0x06, 0x3EDC, 0x99FF},
	{0x06, 0x3EE2, 0xBB88},
	{0x06, 0x3EE4, 0x8836},
	{0x06, 0x3EF0, 0x1CF0},
	{0x06, 0x3EF2, 0x0000},
	{0x06, 0x3EF8, 0x6166},
	{0x06, 0x3EFA, 0x3333},
	{0x06, 0x3EFC, 0x6634},
	{0x06, 0x3276, 0x05DC},
	{0x06, 0x3F00, 0x9D05},
	{0x06, 0x3ED2, 0xFA86},
	{0x06, 0x3EEE, 0xA4FE},
	{0x06, 0x30BA, 0x7602},
	{0x06, 0x3180, 0xC24F},
	{0x06, 0x3ECC, 0x6E42},
	{0x06, 0x3ECC, 0x0E42},
	{0x06, 0x3EEC, 0x0C0C},
	{0x06, 0x3EE8, 0xAAE4},
	{0x06, 0x3EE6, 0x3363},
	{0x06, 0x3EE6, 0x3363},
	{0x06, 0x3EE8, 0xAAE4},
	{0x06, 0x3EE8, 0xAAE4},
	{0x06, 0x3102, 0x5000},
	{0x06, 0x3060, 0x000D},
	{0x06, 0x3ED0, 0xFF44},
	{0x06, 0x3ED2, 0xAA86},
	{0x06, 0x3ED4, 0x031F},
	{0x06, 0x3EEE, 0xA4AA},
	{0x06, 0x301a, 0x2058},

	{0x00, AR0234_TABLE_END, 0x00},
};

static struct index_reg_8 tp_colorbars[] = {
	{0x06,0x3070, 0x2},

	{0x00,AR0234_TABLE_END, 0x00},
};

enum {
	AR0234_MODE_1920X1080_CROP_30FPS,
	AR0234_MODE_START_STREAM,
	AR0234_MODE_STOP_STREAM,
	AR0234_MODE_Hawk_Dser_Ser,
	AR0234_MODE_Owl_Dser_Ser,
	AR0234_MODE_TEST_PATTERN
};

static struct index_reg_8 *mode_table[] = {
	[AR0234_MODE_1920X1080_CROP_30FPS]
		= ar0234_1920x1080_crop_30fps,
	[AR0234_MODE_START_STREAM]
		= ar0234_start,
	[AR0234_MODE_STOP_STREAM]
		= ar0234_stop,
	[AR0234_MODE_Hawk_Dser_Ser] = ar0234_Hawk_Dser_Ser,
	[AR0234_MODE_Owl_Dser_Ser] = ar0234_Owl_Dser_Ser,
	[AR0234_MODE_TEST_PATTERN] = tp_colorbars,

};

static const int ar0234_30fps[] = {
	30,
};

static const int ar0234_60fps[] = {
	60,
};

static const int ar0234_120fps[] = {
	120,
};

static const struct camera_common_frmfmt ar0234_frmfmt[] = {
	{{1920, 1200}, ar0234_30fps, 1, 0, AR0234_MODE_1920X1080_CROP_30FPS},
};
#endif /* __AR0234_I2C_TABLES__ */

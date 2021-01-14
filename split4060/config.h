#ifndef CONFIG_H
#define CONFIG_H

#define COMBO_COUNT 2
#define COMBO_TERM 100

#include "config_common.h"
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0002
#define MANUFACTURER    ntope
#define PRODUCT         split4060
#define DESCRIPTION     A split 40 in a 60 case

#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5, B7, D5 }
#define MATRIX_COL_PINS { C7, F1, F0, B6, B2, B3 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F7 }
#define ENCODER_RESOLUTION 4

#define DIODE_DIRECTION COL2ROW

#define RGBLED_NUM 0

#endif

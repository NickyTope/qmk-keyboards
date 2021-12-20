#ifndef CONFIG_H
#define CONFIG_H

#define COMBO_COUNT 2
#define COMBO_TERM 100

#include "config_common.h"
#define VENDOR_ID       0x0420
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0002
#define MANUFACTURER    ntope
#define PRODUCT         chris_macropad
#define DESCRIPTION     brother needs a scroll wheel

#define MATRIX_ROWS 4
#define MATRIX_COLS 2

#define MATRIX_ROW_PINS { D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B1, B3 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { D4 }
#define ENCODERS_PAD_B { C6 }
#define ENCODER_RESOLUTION 4

#define DIODE_DIRECTION COL2ROW

#define SOFT_SERIAL_PIN D0
#define SPLIT_USB_DETECT
#define MASTER_LEFT

#define RGBLED_NUM 0

#endif

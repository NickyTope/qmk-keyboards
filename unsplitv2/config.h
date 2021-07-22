#ifndef CONFIG_H
#define CONFIG_H

#define COMBO_COUNT 3
#define COMBO_TERM 100

#include "config_common.h"
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6062
#define DEVICE_VER      0x0002
#define MANUFACTURER    ntope
#define PRODUCT         unsplit2
#define DESCRIPTION     A conjoined split 40 that fits in a standard 60 case

#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { D3, D2, D1, D0, D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B4, B5, B6, B2, B3, B1 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F6 }
#define ENCODERS_PAD_B { F5 }
#define ENCODER_RESOLUTION 4

#define DIODE_DIRECTION ROW2COL

#define RGB_DI_PIN F7
#define RGBLED_NUM 10
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LED_MAP { 0, 1, 5, 4, 2, 3, 6, 7, 8, 9 }

#endif

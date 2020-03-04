#ifndef NTOPE_H
#define NTOPE_H

#include "quantum.h"

#define KEYMAP( \
	L00, L01, L02, L03, L04, L05, L06, \
	L10, L11, L12, L13, L14, L15, L16, \
	L20, L21, L22, L23, L24, L25, L26, \
            L32, L33, L34 \
) \
{ \
	{ L00, L01, L02, L03, L04, L05, L06 }, \
	{ L10, L11, L12, L13, L14, L15, L16 }, \
	{ L20, L21, L22, L23, L24, L25, L26 }, \
	{ KC_NO, KC_NO, L32, L33, L34, KC_NO, KC_NO } \
}

#endif

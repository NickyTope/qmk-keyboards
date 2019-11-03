#ifndef NTOPE_H
#define NTOPE_H

#include "quantum.h"

#define KEYMAP( \
	L00, L01, L02, L03, L04, L05, L06, R00, R01, R02, R03, R04, R05, R06, R36,  \
	L10, L11, L12, L13, L14, L15, L16, R10, R11, R12, R13, R14, R15, R16,  \
	L20, L21, L22, L23, L24, L25, L26, R20, R21, R22, R23, R24, R25, R26,  \
	     L31, L32, L33, L34,      L36, R30,      R32, R33, R34, R35, \
			 													L35, R31 \
) \
{ \
	{ L00, L01, L02, L03, L04, L05, L06 }, \
	{ L10, L11, L12, L13, L14, L15, L16 }, \
	{ L20, L21, L22, L23, L24, L25, L26 }, \
	{ KC_NO, L31, L32, L33, L34, L35, L36 }, \
	{ R00, R01, R02, R03, R04, R05, R06 }, \
	{ R10, R11, R12, R13, R14, R15, R16 }, \
	{ R20, R21, R22, R23, R24, R25, R26 }, \
	{ R30, R31, R32, R33, R34, R35, R36 } \
}

#endif

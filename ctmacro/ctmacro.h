#ifndef CT_H
#define CT_H

#include "quantum.h"

#define LAYOUT_ct( \
    R1, R2, R3, ENC, R4 \
) \
{ \
  { KC_NO, R1 }, \
  { KC_NO, R2 }, \
  { KC_NO, R3 }, \
  { R4, ENC } \
}

#endif

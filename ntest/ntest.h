#pragma once
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"
#include "i2c_master.h"
#include "matrix.h"


extern i2c_status_t mcp23018_status;
#define ERGODOX_EZ_I2C_TIMEOUT 1000
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

#define I2C_LEFT        0x20
#define I2C_LEFT_WRITE  ( (I2C_LEFT<<1) | I2C_WRITE )
#define I2C_LEFT_READ   ( (I2C_LEFT<<1) | I2C_READ  )
#define I2C_RIGHT        0x27
#define I2C_RIGHT_WRITE  ( (I2C_RIGHT<<1) | I2C_WRITE )
#define I2C_RIGHT_READ   ( (I2C_RIGHT<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

void init_ergodox(void);
uint8_t init_mcp23018(void);

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT(                                                          \
    L00,L01, R00,R01, \
    L10,L11, R10,R11)  \
                                                                         \
   /* matrix positions */                                                \
    {			\
    { L00, L01 },     \
    { L10, L11 },     \
    { R00, R01 },     \
    { R10, R11 }     \
}

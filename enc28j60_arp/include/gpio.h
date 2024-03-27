#pragma once

#include "peripherals/gpio.h"

//GPFSEL Register
typedef enum _GpioFunc {
    GFInput = 0,
    GFOutput = 1,
    GFAlt0 = 4,
    GFAlt1 = 5,
    GFAlt2 = 6,
    GFAlt3 = 7,
    GFAlt4 = 3,
    GFAlt5 = 2
} GpioFunc;

//GPIO_PUP_PDN_CNTRL_REG Register
typedef enum _GpioPUPPDNCNTRL {
    GRNo = 0,   // 00 = No resistor is selected
    GRUP = 1,   // 01 = Pull up resistor is selected
    GRPD = 2,   // 10 = Pull down resistor is selected
    GPres = 3   // 11 = Reserved (reset)
} GpioPUPPDNCNTRL;


void gpio_pin_set_func(u8 pinNumber, GpioFunc func);

void gpio_pin_enable(u8 pinNumber);
u8 gpio_set(u8 pinNumber, u8 value);
u8 gpio_clear(u8 pinNumber, u8 value);
void gpio_setPinOutputBool(u8 pinNumber, u8 onOrOff);
void gpio_initOutputPinWithPullNone(u8 pinNumber);

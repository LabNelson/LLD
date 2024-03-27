#include "../include/gpio.h"
#include "utils.h"

enum {
    GPFSEL0         = PBASE + 0x200000,
    GPSET0          = PBASE + 0x20001C,
    GPCLR0          = PBASE + 0x200028,
    GPPUPPDN0       = PBASE + 0x2000E4,
    GPIO_MAX_PIN       = 53
};

enum {
    Pull_None = 0,
    Pull_Down = 1, // Are down and up the right way around?
    Pull_Up = 2
};

void mmio_write(long reg, unsigned int val) { *(volatile unsigned int *)reg = val; }
unsigned int mmio_read(long reg) { return *(volatile unsigned int *)reg; }

unsigned int gpio_call(unsigned int pin_number, unsigned int value, unsigned int base, unsigned int field_size, unsigned int field_max) {
    unsigned int field_mask = (1 << field_size) - 1;
  
    if (pin_number > field_max) return 0;
    if (value > field_mask) return 0; 

    unsigned int num_fields = 32 / field_size;
    unsigned int reg = base + ((pin_number / num_fields) * 4);
    unsigned int shift = (pin_number % num_fields) * field_size;

    unsigned int curval = mmio_read(reg);
    curval &= ~(field_mask << shift);
    curval |= value << shift;
    mmio_write(reg, curval);

    return 1;
}

u8 gpio_set     (u8 pin_number, u8 value) { return gpio_call(pin_number, value, GPSET0, 1, GPIO_MAX_PIN); }
u8 gpio_clear   (u8 pin_number, u8 value) { return gpio_call(pin_number, value, GPCLR0, 1, GPIO_MAX_PIN); }
u8 gpio_pull    (unsigned int pin_number, unsigned int value) { return gpio_call(pin_number, value, GPPUPPDN0, 2, GPIO_MAX_PIN); }

void gpio_pin_set_func(u8 pinNumber, GpioFunc func) {
    u8 bitStart = (pinNumber * 3) % 30;
    u8 reg = pinNumber / 10;

    u32 selector = REGS_GPIO->func_select[reg];
    selector &= ~(7 << bitStart);
    selector |= (func << bitStart);

    REGS_GPIO->func_select[reg] = selector;
}

void gpio_pin_enable(u8 pinNumber) {
    REGS_GPIO->pupd_enable = 0;
    delay(150);
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 1 << (pinNumber % 32);
    delay(150);
    REGS_GPIO->pupd_enable = 0;
    REGS_GPIO->pupd_enable_clocks[pinNumber / 32] = 0;
}
/*
// Im currently working here
void gpio_pin_pullupdown (u8 pinNumber) {

    
}
*/

void gpio_initOutputPinWithPullNone(u8 pinNumber) {
    gpio_pull(pinNumber, Pull_None);
    gpio_pin_set_func(pinNumber, GFOutput);
}

void gpio_setPinOutputBool(u8 pinNumber, u8 onOrOff) {
    if (onOrOff) {
        gpio_set(pinNumber, 1);
    } else {
        gpio_clear(pinNumber, 1);
    }
}
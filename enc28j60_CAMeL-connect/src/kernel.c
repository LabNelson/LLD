#include "common.h"
#include "mini_uart.h"
#include "printf.h"
#include "irq.h"
#include "../include/timer.h"
#include "../include/peripherals/timer.h"
#include "i2c.h"
#include "spi.h"

#include "../include/enc28j60.h"

void putc(void *p, char c) {
    if (c == '\n') {
        uart_send('\r');
    }

    uart_send(c);
}

u32 HAL_GetTick(void) {
    unsigned int hi = REGS_TIMER->counter_hi;
    unsigned int lo = REGS_TIMER->counter_lo;

    //double check hi value didn't change after setting it...
    if (hi != REGS_TIMER->counter_hi) {
        hi = REGS_TIMER->counter_hi;
        lo = REGS_TIMER->counter_lo;
    }

    return ((unsigned long)hi << 32) | lo;
}

void HAL_Delay(unsigned int ms) {
    unsigned long start = HAL_GetTick();

    while(HAL_GetTick() < start + (ms * 1000));
}

u32 get_el();


void kernel_main() {
    uart_init();
    init_printf(0, putc);
    uart_send_string("\nRasperry PI Bare Metal OS Initializing...\n");

    irq_init_vectors();
    enable_interrupt_controller();
    irq_barrier();
    irq_enable();
    timer_init();

#if RPI_VERSION == 3
    printf("\tBoard: Raspberry PI 3\n");
#endif

#if RPI_VERSION == 4
    printf("\tBoard: Raspberry PI 4\n");
#endif

    printf("\nException Level: %d\n", get_el());

    printf("Sleeping 200 ms...\n");
    timer_sleep(200);

    printf("Initializing SPI...\n");
    spi_init();
    /*
    uint8_t sendcode, receivecode;
    uint8_t *send, *receive;
    send = &sendcode;
    receive = &receivecode;
    *send = 0xFF;
    spi_send_recv(0,send,receive,1);
    printf("SPI loopback: %d \n",receivecode);
*/

    init_network();
    for (u8 i = 0; i < 10; i++)
    {
        arp_test();
        timer_sleep(100);
    }
    printf("ARP TEST DONE!\n");

    printf("Let's send your keyboard input!\n");
    while(1) {
        uart_send(uart_recv());
    }
}

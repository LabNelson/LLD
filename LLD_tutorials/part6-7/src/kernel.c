#include "common.h"
#include "mini_uart.h"
#include "printf.h"

void putc(void *p, char c) {
    if (c == '\n') {
        uart_send('\r');
    }

    uart_send(c);
}

u32 get_el();

void kernel_main() {
    uart_init();
    init_printf(0, putc);
    printf("\nRasperry PI Bare Metal OS Initializing...\n");

#if RPI_VERSION == 3
    printf("\tBoard: Raspberry PI 3\n");
#endif

#if RPI_VERSION == 4
    printf("\tBoard: Raspberry PI 4\n");
#endif

    printf("\nException Level: %d\n", get_el());
    printf("size of char: %d\n", sizeof(char));
    printf("size of int: %d\n", sizeof(int));
    printf("size of float: %d\n", sizeof(float));
    printf("size of double: %d\n", sizeof(double));
    printf("size of long: %d\n", sizeof(long));

    while(1) {
        uart_send(uart_recv());
    }
}

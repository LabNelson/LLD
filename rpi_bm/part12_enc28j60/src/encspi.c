#include "../include/spi.h"

void ENC_SPI_Select(u8 select) {
    if (true == select)
    {
        spi_chip_select(0);
    }else
    {
        spi_chip_deselect(0);
    }
    
    //spi_chip_select(!truefalse); // If it's true, select 0 (the ENC), if false, select 1 (i.e. deselect the ENC)
}

void ENC_SPI_SendBuf(u8 *master2slave, u8 *slave2master, u32 bufferSize) {
    spi_chip_select(0);
    spi_send_recv(0, master2slave, slave2master, bufferSize);
    spi_chip_deselect(0);
}

void ENC_SPI_Send(u8 command) {
    spi_chip_select(0);
    spi_send(0, &command, 1);
    spi_chip_deselect(0);
}

void ENC_SPI_SendWithoutSelection(u8 command) {
    spi_send(0, &command, 1);
}

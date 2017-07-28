#ifndef _SRC_SPI_H
#define _SRC_SPI_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

#define	P_SCK			B,5
#define	P_MOSI			B,3
#define	P_MISO			B,4
#define P_CS			B,2

void spi_init(void);
void spi_write_register(uint8_t adress, uint8_t data);
uint8_t spi_read_register(uint8_t adress);

#endif
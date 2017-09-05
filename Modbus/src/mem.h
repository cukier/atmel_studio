#ifndef SRC_MEM_H
#define SRC_MEM_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

bool mem_init();
bool mem_ready();
bool mem_read_data(uint16_t address, uint8_t *data, uint16_t size);
bool mem_write_data(uint16_t address, uint8_t *data, uint16_t size);


#endif
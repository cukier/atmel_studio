#ifndef SRC_MEM_H
#define SRC_MEM_H

#include "sys.h"

#include <stdint.h>
#include <stdbool.h>

bool mem_init();
bool mem_ready();
uint16_t mem_read_word(uint16_t address);
void mem_write_word(uint16_t address, uint16_t value);
bool mem_read_data(uint16_t address, uint8_t *data, uint16_t size);
bool mem_write_data(uint16_t address, uint8_t *data, uint16_t size);
uint32_t mem_get_size(void);


#endif
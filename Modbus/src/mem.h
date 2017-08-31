#ifndef SRC_MEM_H
#define SRC_MEM_H

#include "sys.h"
#ifdef USE_EXTERNAL_EEPROM
#include "eeprom.h"
#endif
#include <stdint.h>
#include <stdbool.h>

bool mem_init();
bool mem_ready();
bool mem_read_data(uint16_t from, uint16_t len, uint8_t *data);
bool mem_write_data(uint16_t from, uint16_t len, uint8_t *data);


#endif
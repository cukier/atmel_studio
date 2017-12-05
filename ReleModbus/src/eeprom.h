/*
 * eeprom.h
 *
 * Created: 10/04/2017 15:55:02
 *  Author: cuki
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <stdint.h>
#include <stdbool.h>
#include "sys.h"

uint8_t ext_eprom_read_data(uint16_t address, uint8_t *data, uint16_t size);
uint8_t ext_eprom_write_data(uint16_t address, uint8_t *data, uint16_t size);
uint8_t ext_eprom_read_word(uint16_t address, uint16_t *data);
uint8_t ext_eprom_read_word_data(uint16_t address, uint16_t *data, uint16_t size);
uint8_t ext_eprom_write_word_data(uint16_t address, uint16_t *data, uint16_t size);
uint8_t ext_eprom_init(void);
uint32_t ext_eprom_get_size(void);
bool ext_eprom_ready(void);

#endif /* EEPROM_H_ */
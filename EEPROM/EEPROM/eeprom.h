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

uint8_t eeprom_read_word(uint16_t address, uint16_t *data);
uint8_t eeprom_read_data(uint16_t address, uint16_t *data, uint16_t size);
uint8_t eeprom_write_data(uint16_t address, uint16_t *data, uint16_t size);
uint8_t eeprom_init(void);

#endif /* EEPROM_H_ */
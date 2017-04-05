/*
* i2c.h
*
* Created: 03/04/2017 13:01:11
*  Author: cuki
*/


#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include <stdbool.h>

#define SUCCESS		0
#define ERROR		1

void TWISetAddress(uint8_t address);
void TWIInit(uint8_t address);
void TWIStart(void);
void TWIWrite(uint8_t u8data);
uint8_t TWIReadACK(void);
uint8_t TWIReadNACK(void);
uint8_t TWIGetStatus(void);
uint8_t EEWriteByte(uint16_t u16addr, uint8_t u8data);
uint8_t EEReadByte(uint16_t u16addr, uint8_t *u8data);
uint8_t EEWritePage(uint8_t page, uint8_t *u8data);
uint8_t EEReadPage(uint8_t page, uint8_t *u8data);

#endif /* I2C_H_ */
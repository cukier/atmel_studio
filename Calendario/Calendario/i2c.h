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

void TWISetPageSize(uint16_t pSize);
void TWISetWordAddress(void);
void TWIResetWordAddress(void);
void TWISetAddress(uint8_t address);
void TWIInit(void);
uint8_t TWIWriteByte(uint16_t u16addr, uint8_t u8data);
uint8_t TWIReadByte(uint16_t u16addr, uint8_t *u8data);
uint8_t TWIReadData(uint16_t address, uint8_t *data, uint16_t size);
uint8_t TWIWriteData(uint16_t address, uint8_t *data, uint16_t size);
uint8_t TWIWritePage(uint8_t page, uint8_t *u8data);
uint8_t TWIReadePage(uint8_t page, uint8_t *u8data);

#endif /* I2C_H_ */
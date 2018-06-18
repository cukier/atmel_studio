#ifndef _SRC_I2CSLAVE_H
#define _SRC_I2CSLAVE_H

void i2c_init(uint8_t slv_addr);
void i2c_stop();
void i2c_setCallback(void (*recv)(uint8_t));

#endif
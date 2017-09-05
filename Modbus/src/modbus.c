/*
* modbus.c
*
* Created: 04/04/2017 21:19:19
*  Author: cuki
*/

#include "modbus.h"
#include "uart.h"
#include "i2c.h"
#include "eeprom.h"
#include "mem.h"
#include <stdlib.h>

#define MB_MAX_SIZE mem_get_size()

typedef enum modbus_command_exception_code {
	EXCEPTION_CODE_0,
	EXCEPTION_CODE_1,
	EXCEPTION_CODE_2,
	EXCEPTION_CODE_3,
	EXCEPTION_CODE_4
} modbus_command_exception_code_t;

typedef enum exceptions {
	NO_EXCEPTION,
	TIMEOUT_EXCEPTION,
	OUT_OF_MEMORY_EXCEPTION,
	CRC_EXCEPTION,
	NO_SERIAL_PORT_EXCEPTION
} exception_t;

typedef enum modbus_fields {
	MODBUS_FIELDS_ADDRESS,
	MODBUS_FIELDS_FUNCTION,
	MODBUS_FIELDS_REGISTER_ADDRESS_H,
	MODBUS_FIELDS_REGISTER_ADDRESS_L,
	MODBUS_FIELDS_REGISTER_VALUE_H,
	MODBUS_FIELDS_REGISTER_VALUE_L,
	MODBUS_FIELDS_BYTE_COUNT
} modbus_fields_t;

typedef enum modbus_commands {
	NO_COMMAND,
	READ_COILS_COMMAND,
	READ_DISCRETE_INPUT_COMMAND,
	READ_HOLDING_REGISTERS_COMMAND,
	READ_INPUT_REGISTERS_COMMAND,
	WRITE_SINGLE_COIL_COMMAND,
	WRITE_SINGLE_REGISTER_COMMAND,
	READ_EXCEPTION_STATUS_COMMAND,
	DIAGNOSTICS_COMMAND,
	GET_COMM_EVENT_COUNTER_COMMAND = 0x0B,
	GET_COMM_EVENT_LOG_COMMAND,
	WRITE_MULTIPLE_COILS_COMMAND = 0x0F,
	WRITE_MULTIPLE_REGISTERS_COMMAND,
	REPORT_SLAVE_ID_COMMAND,
	READ_FILE_RECORD_COMMAND = 0x14,
	WRITE_FILE_RECORD_COMMAND,
	MASK_WRITE_REGISTER_COMMAND,
	READ_WRITE_MULTIPLE_REGISTERS_COMMAND,
	READ_FIFO_QUEQUE_COMMAND,
	READ_DEVICE_IDENT_COMMAND = 0x2B
} modbus_command_t;

typedef struct modbus_response {
	uint8_t address;
	uint8_t function;
	uint8_t response_size;
	uint8_t *data;
	uint16_t crc;
} modbus_response_t;

typedef struct modbus_request {
	uint8_t address;
	uint8_t function;
	uint16_t start_address;
	uint16_t size;
	uint8_t byte_count;
	uint8_t *data;
	uint16_t crc;
} modbus_request_t;

static const uint16_t wCRCTable[] = { 0X0000, 0XC0C1, 0XC181, 0X0140, 0XC301,
	0X03C0, 0X0280, 0XC241, 0XC601, 0X06C0, 0X0780, 0XC741, 0X0500, 0XC5C1,
	0XC481, 0X0440, 0XCC01, 0X0CC0, 0X0D80, 0XCD41, 0X0F00, 0XCFC1, 0XCE81,
	0X0E40, 0X0A00, 0XCAC1, 0XCB81, 0X0B40, 0XC901, 0X09C0, 0X0880, 0XC841,
	0XD801, 0X18C0, 0X1980, 0XD941, 0X1B00, 0XDBC1, 0XDA81, 0X1A40, 0X1E00,
	0XDEC1, 0XDF81, 0X1F40, 0XDD01, 0X1DC0, 0X1C80, 0XDC41, 0X1400, 0XD4C1,
	0XD581, 0X1540, 0XD701, 0X17C0, 0X1680, 0XD641, 0XD201, 0X12C0, 0X1380,
	0XD341, 0X1100, 0XD1C1, 0XD081, 0X1040, 0XF001, 0X30C0, 0X3180, 0XF141,
	0X3300, 0XF3C1, 0XF281, 0X3240, 0X3600, 0XF6C1, 0XF781, 0X3740, 0XF501,
	0X35C0, 0X3480, 0XF441, 0X3C00, 0XFCC1, 0XFD81, 0X3D40, 0XFF01, 0X3FC0,
	0X3E80, 0XFE41, 0XFA01, 0X3AC0, 0X3B80, 0XFB41, 0X3900, 0XF9C1, 0XF881,
	0X3840, 0X2800, 0XE8C1, 0XE981, 0X2940, 0XEB01, 0X2BC0, 0X2A80, 0XEA41,
	0XEE01, 0X2EC0, 0X2F80, 0XEF41, 0X2D00, 0XEDC1, 0XEC81, 0X2C40, 0XE401,
	0X24C0, 0X2580, 0XE541, 0X2700, 0XE7C1, 0XE681, 0X2640, 0X2200, 0XE2C1,
	0XE381, 0X2340, 0XE101, 0X21C0, 0X2080, 0XE041, 0XA001, 0X60C0, 0X6180,
	0XA141, 0X6300, 0XA3C1, 0XA281, 0X6240, 0X6600, 0XA6C1, 0XA781, 0X6740,
	0XA501, 0X65C0, 0X6480, 0XA441, 0X6C00, 0XACC1, 0XAD81, 0X6D40, 0XAF01,
	0X6FC0, 0X6E80, 0XAE41, 0XAA01, 0X6AC0, 0X6B80, 0XAB41, 0X6900, 0XA9C1,
	0XA881, 0X6840, 0X7800, 0XB8C1, 0XB981, 0X7940, 0XBB01, 0X7BC0, 0X7A80,
	0XBA41, 0XBE01, 0X7EC0, 0X7F80, 0XBF41, 0X7D00, 0XBDC1, 0XBC81, 0X7C40,
	0XB401, 0X74C0, 0X7580, 0XB541, 0X7700, 0XB7C1, 0XB681, 0X7640, 0X7200,
	0XB2C1, 0XB381, 0X7340, 0XB101, 0X71C0, 0X7080, 0XB041, 0X5000, 0X90C1,
	0X9181, 0X5140, 0X9301, 0X53C0, 0X5280, 0X9241, 0X9601, 0X56C0, 0X5780,
	0X9741, 0X5500, 0X95C1, 0X9481, 0X5440, 0X9C01, 0X5CC0, 0X5D80, 0X9D41,
	0X5F00, 0X9FC1, 0X9E81, 0X5E40, 0X5A00, 0X9AC1, 0X9B81, 0X5B40, 0X9901,
	0X59C0, 0X5880, 0X9841, 0X8801, 0X48C0, 0X4980, 0X8941, 0X4B00, 0X8BC1,
	0X8A81, 0X4A40, 0X4E00, 0X8EC1, 0X8F81, 0X4F40, 0X8D01, 0X4DC0, 0X4C80,
	0X8C41, 0X4400, 0X84C1, 0X8581, 0X4540, 0X8701, 0X47C0, 0X4680, 0X8641,
0X8201, 0X42C0, 0X4380, 0X8341, 0X4100, 0X81C1, 0X8081, 0X4040 };

static volatile uint16_t m_address;

bool slave_init(uint16_t address)
{
	uart_init(UART_BAUD_SELECT(UART_BAUD_RATE, F_CPU));
	m_address = address;
	mem_init();
	
	return true;
}

uint16_t make16(uint8_t varhigh, uint8_t varlow) {
	return (uint16_t) (varhigh & 0xff) * 0x100 + (varlow & 0xff);
}

uint8_t make8(uint32_t var, uint8_t offset) {
	return (uint8_t) (((var >> (offset * 8)) & 0xff));
}

uint16_t CRC16(uint8_t *nData, uint16_t wLength) {
	uint8_t nTemp;
	uint16_t wCRCWord = 0xFFFF;

	while (wLength--) {
		nTemp = *nData++ ^ wCRCWord;
		wCRCWord >>= 8;
		wCRCWord ^= wCRCTable[nTemp];
	}

	return wCRCWord;
}

bool modbus_send(uint8_t *data, uint16_t i_size) {
	uart_send(data, i_size);
	return true;
}

uint8_t check_CRC(uint8_t *resp, modbus_command_t command) {
	uint16_t ar_size, crc_check, crc_in, cont;
	uint8_t *arr;
	
	ar_size = 0;
	crc_check = 0;
	crc_in = 0;
	cont = 0;
	arr = NULL;

	switch (command) {
		case READ_HOLDING_REGISTERS_COMMAND:
		case READ_COILS_COMMAND:
		case READ_DISCRETE_INPUT_COMMAND:
		ar_size = resp[2] + 3;
		break;
		case WRITE_SINGLE_REGISTER_COMMAND:
		case WRITE_MULTIPLE_REGISTERS_COMMAND:
		ar_size = 6;
		break;
		default:
		break;
	}

	arr = (uint8_t *) malloc((size_t) (ar_size * sizeof(uint8_t)));

	if (arr == NULL) {
		free(arr);
		return 0;
	}

	for (cont = 0; cont < ar_size; ++cont)
	{
		arr[cont] = resp[cont];
	}
	
	crc_in = make16(resp[ar_size + 1], resp[ar_size]);
	crc_check = CRC16(arr, ar_size);
	free(arr);

	return (uint8_t) (crc_check == crc_in);
}

bool return_error(modbus_command_t command,
modbus_command_exception_code_t error) {
	uint8_t resp[5], ex_code;
	uint16_t crc;

	switch (command) {
		case READ_HOLDING_REGISTERS_COMMAND:
		ex_code = 0x83;
		break;
		case WRITE_SINGLE_REGISTER_COMMAND:
		ex_code = 0x86;
		break;
		default:
		case NO_COMMAND:
		case READ_COILS_COMMAND:
		case READ_DISCRETE_INPUT_COMMAND:
		case READ_INPUT_REGISTERS_COMMAND:
		case WRITE_SINGLE_COIL_COMMAND:
		ex_code = 0;
		break;
	}

	resp[0] = m_address;
	resp[1] = ex_code;
	resp[2] = error;
	crc = CRC16(resp, 3);
	resp[3] = (uint8_t) ((crc & 0xFF00) >> 8);
	resp[4] = (uint8_t) (crc & 0xFF);

	modbus_send(resp, 5);

	return true;
}

bool modbus_slave(void) {
	uint8_t response[MODBUS_SLV_BUFFER], request[MODBUS_SLV_BUFFER], tmp_var[2];
	uint16_t register_value, register_address, b_count, cont,
	request_crc, aux_addr, index_rda, my_crc;
	bool ret;

	ret = false;
	index_rda = 0;
	index_rda = uart_available();

	if (index_rda != 0) {
		uart_get(request, index_rda);
		register_value = (request[MODBUS_FIELDS_REGISTER_VALUE_H] << 8) |
		request[MODBUS_FIELDS_REGISTER_VALUE_L];
		register_address = (request[MODBUS_FIELDS_REGISTER_ADDRESS_H] << 8) |
		request[MODBUS_FIELDS_REGISTER_ADDRESS_L];
		b_count = request[MODBUS_FIELDS_BYTE_COUNT];
		aux_addr = 2 * register_address;
		request_crc = ((request[index_rda - 1] << 8) | (request[index_rda - 2]));
		my_crc = CRC16(request, index_rda - 2);

		if ((m_address == request[MODBUS_FIELDS_ADDRESS]) && my_crc == request_crc)
		{
			switch (request[MODBUS_FIELDS_FUNCTION])
			{
				case READ_HOLDING_REGISTERS_COMMAND:
				if (register_value == 0 || register_value > 0x7D)
				{
					ret = return_error(READ_HOLDING_REGISTERS_COMMAND,
					EXCEPTION_CODE_3);
				}
				else if (((register_value + register_address) * 2) > (uint32_t) MB_MAX_SIZE)
				{
					ret = return_error(READ_HOLDING_REGISTERS_COMMAND,
					EXCEPTION_CODE_2);
				}
				else if (!mem_ready())
				{
					ret = return_error(READ_HOLDING_REGISTERS_COMMAND,
					EXCEPTION_CODE_0);
				}
				else
				{
					b_count = 2 * register_value;
					response[0] = m_address;
					response[1] = READ_HOLDING_REGISTERS_COMMAND;
					response[2] = (uint8_t) b_count;
					mem_read_data(aux_addr, &response[3], b_count);
					request_crc = CRC16(response, b_count + 3);
					response[b_count + 3] = (uint8_t) (request_crc & 0xFF);
					response[b_count + 4] = (uint8_t) ((request_crc & 0xFF00) >> 8);
					ret = modbus_send(response, b_count + 5);
				}
				
				break;

				case WRITE_SINGLE_REGISTER_COMMAND:
				if (((register_address + 1) * 2) > (uint32_t) MB_MAX_SIZE)
				{
					ret = return_error(WRITE_SINGLE_REGISTER_COMMAND,
					EXCEPTION_CODE_2);
				}
				else if (!mem_ready())
				{
					ret = return_error(READ_HOLDING_REGISTERS_COMMAND,
					EXCEPTION_CODE_0);
				}
				else
				{
					tmp_var[0] = (uint8_t) ((register_value & 0xFF00) >> 8);
					tmp_var[1] = (uint8_t) (register_value & 0xFF);
					mem_write_data(aux_addr, tmp_var, 2);

					for (cont = 0; cont < index_rda; ++cont)
					{
						response[cont] = request[cont];
					}

					ret = modbus_send(response, index_rda);
				}
				
				break;

				case WRITE_MULTIPLE_REGISTERS_COMMAND:
				if (((register_address * 2) + b_count) > (uint32_t) MB_MAX_SIZE)
				{
					ret = return_error(WRITE_SINGLE_REGISTER_COMMAND,
					EXCEPTION_CODE_2);
				}
				else if (!mem_ready())
				{
					ret = return_error(READ_HOLDING_REGISTERS_COMMAND,
					EXCEPTION_CODE_0);
				}
				else
				{
					mem_write_data(aux_addr, &request[7], b_count);
					response[0] = m_address;
					response[1] = WRITE_MULTIPLE_REGISTERS_COMMAND;
					response[2] = (uint8_t) ((register_address & 0xFF00) >> 8);
					response[3] = (uint8_t) (register_address & 0xFF);
					response[4] = (uint8_t) ((register_value & 0xFF00) >> 8);
					response[5] = (uint8_t) (register_value & 0xFF);
					request_crc = CRC16(response, 6);
					response[6] = (uint8_t) ((request_crc & 0xFF00) >> 8);
					response[7] = (uint8_t) (request_crc & 0xFF);
					ret = modbus_send(response, 8);
				}
				
				break;
			}
		}
	}

	return ret;
}
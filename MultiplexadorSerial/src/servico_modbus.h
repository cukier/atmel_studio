#ifndef _SRC_SERVICO_MODUBS_H
#define _SRC_SERVICO_MODUBS_H

#include "terminais.h"

#include <stdbool.h>
#include <stdint.h>

extern uint16_t listenin(void);
extern uint16_t receive(void);
extern bool get_from_slave(uint8_t *data, uint16_t len);
extern uint16_t send_to_slave(uint8_t *buff);
extern void send_back_to_terminal(uint8_t *buff, enum Terminais terminal);
//extern void get_memoria(void);

#endif
/*
 * sys.h
 *
 * Created: 09/04/2017 09:57:07
 *  Author: cuki
 */ 


#ifndef SYS_H_
#define SYS_H_

#define F_CPU					4000000ULL
#define UART_BAUD_RATE_1		19200

#ifdef USART1_ENABLED
#define UART_BAUD_RATE_2		19200
#endif

#endif /* SYS_H_ */
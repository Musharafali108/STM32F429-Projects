/*
 * uart.h
 *
 *  Created on: Feb 7, 2026
 *      Author: DELL
 */

#ifndef UART_H_
#define UART_H_

void uart1_write(char ch);
void uart1_tx_init(void);
char uart1_read(void);
void uart1_rxtx_init(void);


#endif /* UART_H_ */

#include<stdint.h>
#include "stm32f4xx.h"

#define GPIOAEN			(1<<0)
#define USART1EN		(1<<4)

#define CR1_TE			(1<<3)
#define CR1_UE			(1<<13)
#define SR_TXE			(1<<7)

#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	115200

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate);
void uart1_write(char ch);

int __io_putchar(int ch)
{
	uart1_write(ch);
	return ch;
}
void uart1_tx_init(void)
{
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER &= ~(1<<18);
	GPIOA->MODER |= (1<<19);

	GPIOA->AFR[1] |= (1<<4);
	GPIOA->AFR[1] |= (1<<5);
	GPIOA->AFR[1] |= (1<<6);
	GPIOA->AFR[1] &= ~(1<<7);

	RCC->APB2ENR |= USART1EN;

	uart_set_baudrate(USART1,APB1_CLK,UART_BAUDRATE);

	USART1->CR1 = CR1_TE;

	USART1->CR1 |= CR1_UE;

}

void uart1_write(char ch)
{
  /*Make sure the transmit data register is empty*/
	while(!(USART1->SR & SR_TXE)){}

  /*Write to transmit data register*/
	USART1->DR	=  (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk,  uint32_t BaudRate)
{
	USARTx->BRR =  compute_uart_bd(PeriphClk,BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}



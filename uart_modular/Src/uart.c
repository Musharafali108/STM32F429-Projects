#include"uart.h"

#define GPIOAEN			(1U<<0)
#define UART1EN			(1<<4)

#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ
#define UART_BAUDRATE	115200

#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define SR_TXE			(1U<<7)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t periph_clk,  uint32_t baudrate);
static uint16_t compute_uart_bd(uint32_t periph_clk,uint32_t baudrate);
void uart1_write(int ch);



int __io_putchar(int ch)
{
	uart1_write(ch);
	return ch;
}

void uar1_tx_init(void)
{
	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER &= ~(1<<18);
	GPIOA->MODER |= (1<<19);

	GPIOA->AFR[1] |= (1<<4);
	GPIOA->AFR[1] |= (1<<5);
	GPIOA->AFR[1] |= (1<<6);
	GPIOA->AFR[1] &= ~(1<<7);

	RCC->APB2ENR |= UART1EN;

	uart_set_baudrate(USART1,APB1_CLK,UART_BAUDRATE);

	USART1->CR1 =  CR1_TE;

	USART1->CR1 |= CR1_UE;
}

void uart1_write(int ch)
{
  /*Make sure the transmit data register is empty*/
	while(!(USART1->SR & SR_TXE)){}

  /*Write to transmit data register*/
	USART1->DR	=  ch;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t periph_clk,  uint32_t baudrate)
{
	USARTx->BRR =  compute_uart_bd(periph_clk,baudrate);
}


static uint16_t compute_uart_bd(uint32_t periph_clk,uint32_t baudrate)
{
	return((periph_clk+(baudrate/2U))/baudrate);

}

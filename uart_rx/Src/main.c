//#include<stdio.h>
//#include<stdint.h>
//#include"stm32f4xx.h"
#include"uart.h"

#define GPIOBEN      (1<<1)
#define LEDPIN       (1<<13)
char key;
int main(void)
{
	RCC->AHB1ENR |= GPIOBEN;
	GPIOB->MODER |= (1<<26);
	GPIOB->MODER &= ~(1<<27);

	uar1_tx_init();

	while(1)
	{
		key = uart1_read();
		if(key == '1')
		{
			GPIOB->ODR |= LEDPIN;
		}
		else
		{
			GPIOB->ODR &= ~LEDPIN;
		}
	}
}



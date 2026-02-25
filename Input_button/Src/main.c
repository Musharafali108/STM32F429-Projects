#include "stm32f4xx.h"

#define GPIOBEN			(1<<1)
#define GPIOAEN			(1<<0)

#define BUTTON 			(1<<0)





int main(void)
{
	RCC->AHB1ENR |= GPIOBEN;
	RCC->AHB1ENR |= GPIOAEN;

	/*set GPIOB as a output*/
	GPIOB->MODER |= (1<<26);
	GPIOB->MODER &= ~(1<<27);

	/*set GPIOB as a output*/
	GPIOA->MODER &= ~(1<<0);
	GPIOA->MODER &= ~(1<<1);

	while(1)
	{
		if(GPIOA->IDR & BUTTON)
		{
			GPIOB->ODR |= (1<<13);
		}
		else
		{
			GPIOB->ODR &= ~(1<<13);
		}
	}


}

#include "stm32f4xx.h"

#define GPIOBEN         (1 << 1)
#define LED_PIN         (1 << 13)     // PB13 (LD5)

int main(void)
{
	RCC->AHB1ENR |=  GPIOBEN;

	GPIOB->MODER |= (1U<<26);
	GPIOB->MODER &= ~(1U<<27);

	while(1)
	{
		GPIOB->BSRR = LED_PIN;
		for(volatile int i=0; i<500000; i++);  {}

		GPIOB->BSRR = (1<<29);
		for(volatile int i=0; i<500000; i++);  {}

	}

}

#include "stm32f4xx.h"

#define GPIOBEN         (1 << 1)
#define LED_PIN         (1 << 13)     // PB13 (LD5)

int main(void)
{
	// Enable GPIOB peripheral clock
	RCC->AHB1ENR |=  GPIOBEN;

	//Set pin 26 to 1 and 27 to 0 for output mode
	GPIOB->MODER |= (1U<<26);
	GPIOB->MODER &= ~(1U<<27);

	//Toggle LED
	while(1)
	{
		GPIOB->ODR ^= LED_PIN;
		for(int i = 0; i<1000000 ; i++)  {}
	}

}

#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"

#include "uart.h"

#define GPIOBEN         (1 << 1)
#define LED_PIN         (1 << 13)     // PB13 (LD5)

char key;

int main(void)
{
	 // Enable GPIOB clock
	 RCC->AHB1ENR |= GPIOBEN;

	 // Set PB13 as output
	 GPIOB->MODER &= ~(1U << 27);
	 GPIOB->MODER |=  (1U << 26);

	uart1_rxtx_init();

	while(1)
	{
		key = uart1_read();
		if(key == '1')
		{
			GPIOB->ODR |= LED_PIN;
		}
		else
		{
			GPIOB->ODR &= ~LED_PIN;
		}

	}
}




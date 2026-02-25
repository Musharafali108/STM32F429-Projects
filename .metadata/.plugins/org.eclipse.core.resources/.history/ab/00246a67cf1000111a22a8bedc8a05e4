#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIOBEN         (1 << 1)
#define LED_PIN         (1 << 13)     // PB13 (LD5)

int main(void)
{
	// Enable GPIOB peripheral clock
	RCC->AHB1ENR |=  GPIOBEN;

	//Set pin 26 to 1 and 27 to 0 for output mode
	GPIOB->MODER |= (1U<<26);
	GPIOB->MODER &= ~(1U<<27);

	uart1_tx_init();

	//Toggle LED
	while(1)
	{
		printf("A second passed !! \n\r");
		GPIOB->ODR ^= LED_PIN;
		systickDelayMs(1000);
	}

}





//	port : B
// 	pin  : 13

//Button pin
//port : A
//pin  : 0

//#include<stdint.h>
//
//#define PERIPH_BASE 		(0x40000000UL)
//#define AHB1_OFFSET			(0x00020000UL)
//#define AHB1_BASE			(PERIPH_BASE + AHB1_OFFSET)
//
//#define GPIOB_OFFSET		(0X0400UL)
//#define GPIOB_BASE			(AHB1_BASE + GPIOB_OFFSET)
//
//#define RCC_OFFSET          (0x3800UL)
//#define RCC_BASE 			(AHB1_BASE + RCC_OFFSET)

//#define RCC_AHB1ENR_OFFSET	(0x30UL)
//#define	RCC_AHB1ENR_BASE	(*(volatile unsigned int*)(RCC_BASE + RCC_AHB1ENR_OFFSET))
//
//#define GPIOB_MODER_OFFSET	(0x0000UL)
//#define GPIOB_MODER_BASE	(*(volatile unsigned int*)(GPIOB_BASE + GPIOB_MODER_OFFSET))
//
//#define GPIOB_ODR_OFFSET	(0x14UL)
//#define GPIOB_ODR_BASE		(*(volatile unsigned int*)(GPIOB_BASE + GPIOB_ODR_OFFSET))

//typedef struct
//{
//	volatile uint32_t MODE;
//	volatile uint32_t DUMMY[4];
//	volatile uint32_t ODR;
//}GPIO_TypeDef;
//
//typedef struct
//{
//	volatile uint32_t DUMMY[12];
//	volatile uint32_t AHB1EN;
//
//}RCC_TypeDeF;
//
//#define RCC 	((RCC_TypeDeF*)RCC_BASE)
//#define GPIO	((GPIO_TypeDef*)GPIOB_BASE)
//
//
//int main(void)
//{
//	RCC->AHB1EN |= (1<<1);
//
//	GPIO->MODE |= (1<<26);
//	GPIO->MODE &= ~(1<<27);
//
//	while(1)
//	{
//		GPIO->ODR|= (1<<13);
//		for(int i=1;i<10000000;i++) { }
//
//	}
//}

#include"STM32F429xx.h"
#define GPIOBEN		(1<<1)
#define LED         (0<<13)
#define SET			(1<<13)
#define RESET		(1<<29)

#define GPIOAEN     (1<<0)

#define BTN_PIN     (1<<0)

int main(void)
{
	RCC->AHB1ENR |= GPIOBEN;
	RCC->AHB1ENR |= GPIOAEN;

	GPIOB->MODER |= (1<<26);
	GPIOB->MODER &= ~(1<<27);

	GPIOC->MODER &= ~(1<<0);
	GPIOC->MODER &= ~(1<<1);

	while(1)
	{
		if(GPIOA->IDR & BTN_PIN)
		{

		GPIOB->BSRR |= SET;
		//for(int i=0;i<100000;i++) { }
		}
		else
		{
		GPIOB->BSRR |= RESET;
		//for(int i=0;i<100000;i++) { }
		}

	}
}

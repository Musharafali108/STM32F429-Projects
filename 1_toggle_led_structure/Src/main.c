#include <stdint.h>

#define PERIPH_BASE             (0x40000000UL)
#define AHB1PERIPH_OFFSET       (0x00020000UL)
#define AHB1PERIPH_BASE         (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOB_OFFSET            (0x0400UL)
#define GPIOB_BASE              (AHB1PERIPH_BASE + GPIOB_OFFSET)

#define RCC_OFFSET              (0x3800UL)
#define RCC_BASE                (AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIOBEN                 (1U<<1)      // Enable clock for port B
#define PIN13                   (1U<<13)
#define LED_PIN                 PIN13

//This is the structure of RCC(reset and clock control)
typedef struct
{
  volatile uint32_t DUMMY[12];
  volatile uint32_t AHB1ENR;

} RCC_TypeDef;

//This is the structure of GPIO(general purpose input output)
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;

} GPIO_TypeDef;


#define RCC		    ((RCC_TypeDef*) RCC_BASE)
#define GPIOB		((GPIO_TypeDef*)GPIOB_BASE)


int main(void)
{
    //Enable clock for GPIOB
	RCC->AHB1ENR |= GPIOBEN;

    //Set PB13 as output

	GPIOB->MODER &= ~(1U << 27);
	GPIOB->MODER |=  (1U << 26);

    //Toggle LED continuously
    while (1)
    {
        GPIOB->ODR ^= LED_PIN;
        for (int i = 0; i < 100000; i++) {}  // delay
    }
}








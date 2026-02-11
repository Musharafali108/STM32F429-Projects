
//Where is the led connected?
//Port:  A
//Pin:   5

#define PERIPH_BASE     0x40000000UL
#define AHB1_OFFSET     0x00020000UL
#define AHB1_BASE       (PERIPH_BASE + AHB1_OFFSET)

#define GPIOB_OFFSET    0x0400UL
#define GPIOB_BASE      (AHB1_BASE + GPIOB_OFFSET)

#define RCC_OFFSET      0x3800UL
#define RCC_BASE        (AHB1_BASE + RCC_OFFSET)

#define RCC_EN_OFFSET 	(0x30UL)
#define RCC_AHB1ENR     (*(volatile unsigned int *)(RCC_BASE + RCC_EN_OFFSET))

#define MODE_OFFSET		(0x00UL)
#define GPIOB_MODER     (*(volatile unsigned int *)(GPIOB_BASE + MODE_OFFSET))

#define ODR_OFFSET 		(0x14UL)
#define GPIOB_ODR       (*(volatile unsigned int *)(GPIOB_BASE + ODR_OFFSET))

#define GPIOBEN         (1 << 1)
#define LED_PIN         (1 << 13)     // PB13 (LD5)

int main(void)
{
    // Enable GPIOB clock
    RCC_AHB1ENR |= GPIOBEN;

    // Set PB13 as output
    GPIOB_MODER &= ~(1U << 27);
    GPIOB_MODER |=  (1U << 26);

    while(1)
    {
    	/*Toggle PB13*/
        GPIOB_ODR ^= LED_PIN;
        for(int i = 0; i < 500000; i++){}
    }
}

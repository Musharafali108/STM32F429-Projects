#include "stm32wlxx_hal.h"
#include "string.h"

// UART handle
UART_HandleTypeDef huart2;

// Function prototypes
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_USART2_UART_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_USART2_UART_Init();

  char msg[] = "Hello World\r\n";

  while (1)
  {
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
    HAL_Delay(1000);  // Delay 1 second
  }
}

void MX_USART2_UART_Init(void)
{
  __HAL_RCC_USART2_CLK_ENABLE();  // Enable USART2 clock

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
	  while (1);  // Error
  }
}

void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
}

void SystemClock_Config(void)
{
  // You can use the default reset clock or your Cube-generated clock config
}

void Error_Handler(void)
{
  while (1) {}
}

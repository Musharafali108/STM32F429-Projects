#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"



uint32_t sensor_val;

int main(void)
{
	uart1_tx_init();
	pal_adc_init();

	start_converstion();
	while(1)
	{

		sensor_val = adc_read();
		printf("Sensor value i: %d\n\r",(int)sensor_val);
	}
}




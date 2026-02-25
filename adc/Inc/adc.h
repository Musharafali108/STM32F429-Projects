/*
 * adc.h
 *
 *  Created on: Feb 14, 2026
 *      Author: DELL
 */

#ifndef ADC_H_
#define ADC_H_

#include<stdint.h>

void pal_adc_init(void);
uint32_t adc_read(void);
void start_converstion(void);


/*
void pal_adc_init();
void start_converstion();
uint32_t adc_read();
*/

#endif /* ADC_H_ */

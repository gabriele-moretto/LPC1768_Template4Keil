#include "LPC17xx.h"
#include <stdbool.h>
#include "adc.h"

bool enabled = false;

/*----------------------------------------------------------------------------
  Function that initializes ADC
 *----------------------------------------------------------------------------*/
void ADC_init (void) {

  LPC_PINCON->PINSEL3 |=  (3UL<<30);    /* P1.31 is AD0.5                     */

  LPC_SC->PCONP       |=  (1<<12);      /* Enable power to ADC block          */

  LPC_ADC->ADCR        =  (1<< 5) |     /* select AD0.5 pin                   */
                          (4<< 8) |     /* ADC clock is 25MHz/5               */
                          (1<<21);      /* enable ADC                         */ 

  LPC_ADC->ADINTEN     =  (1<<8);      /* global enable interrupt            */

	enabled = true;
  NVIC_EnableIRQ(ADC_IRQn);             /* enable ADC Interrupt               */
}

void ADC_measure (void) {
	if(enabled) {
		LPC_ADC->ADCR |=  (1<<24);            /* Start A/D Conversion 				*/
	}
}	

void ADC_enable() {
	enabled = true;
}

void ADC_disable() {
	enabled = false;
}
#include <string.h>

/* lib_adc.c */
void ADC_init(void);
void ADC_measure(void);
void ADC_enable();
void ADC_disable();

/* IRQ_adc.c */
void ADC_IRQHandler(void);

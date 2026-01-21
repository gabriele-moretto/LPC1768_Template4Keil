/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           lib_timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        atomic functions to be used by higher sw levels
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <stdbool.h>
#include "LPC17xx.h"
#include "timer.h"

LPC_TIM_TypeDef *LPC_TIM(uint8_t timer_num) {
	switch (timer_num) {
		case TIMER0:
			return LPC_TIM0;
			break;
		case TIMER1:
			return LPC_TIM1;
			break;
		case TIMER2:
			return LPC_TIM2;
			break;
		case TIMER3:
			return LPC_TIM3;
			break;
	}
	return LPC_TIM0;
}

int TIMER_IRQn(uint8_t timer_num) {
	switch (timer_num) {
		case TIMER0:
			return TIMER0_IRQn;
			break;
		case TIMER1:
			return TIMER1_IRQn;
			break;
		case TIMER2:
			return TIMER2_IRQn;
			break;
		case TIMER3:
			return TIMER3_IRQn;
			break;
	}
	return TIMER0_IRQn;
}

/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void enable_timer( uint8_t timer_num ) {
	LPC_TIM(timer_num)->TCR = 1;
  return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void disable_timer( uint8_t timer_num ) {
	LPC_TIM(timer_num)->TCR = 0;
  return;
}

/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** parameters:			timer number: 0 or 1
** Returned value:		None
**
******************************************************************************/
void reset_timer( uint8_t timer_num ) {
  uint32_t regVal;

	regVal = LPC_TIM(timer_num)->TCR;
	regVal |= 0x02;
	LPC_TIM(timer_num)->TCR = regVal;
	
  return;
}

void init_timer ( uint8_t timer_num, uint32_t t_MR0, uint32_t t_MR1, uint32_t t_MR2, uint32_t t_MR3) {
	
	if(t_MR0 > 0) {
		LPC_TIM(timer_num)->MR0 = t_MR0;
	}
	
	if(t_MR1 > 0) {
		LPC_TIM(timer_num)->MR1 = t_MR1;
	}
	
	if(t_MR2 > 0) {
		LPC_TIM(timer_num)->MR2 = t_MR2;
	}
	
	if(t_MR3 > 0) {
		LPC_TIM(timer_num)->MR3 = t_MR3;
	}
	
	NVIC_EnableIRQ(TIMER_IRQn(timer_num));
	NVIC_SetPriority(TIMER_IRQn(timer_num), 0);
}

void disable_timer_interrupt(uint8_t timer_num) {
	NVIC_DisableIRQ(TIMER_IRQn(timer_num));
	return;
}

void enable_timer_interrupt(uint8_t timer_num) {
	NVIC_EnableIRQ(TIMER_IRQn(timer_num));
	return;
}

void disable_interrupt_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR &= ~(1 << (3*mr_num));
	return;
}

void enable_interrupt_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR |= (1 << (3*mr_num));
	return;
}

void disable_reset_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR &= ~(1 << (3*mr_num + 1));
	return;
}

void enable_reset_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR |= (1 << (3*mr_num + 1));
	return;
}

void disable_stop_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR &= ~(1 << (3*mr_num + 2));
	return;
}

void enable_stop_on_match(uint8_t timer_num, uint8_t mr_num) {
	LPC_TIM(timer_num)->MCR |= (1 << (3*mr_num + 2));
	return;
}

uint32_t get_timer_counter(uint8_t timer_num) {
	return LPC_TIM(timer_num)->TC;
}

bool MR_interrupt(uint8_t timer_num, uint8_t mr_num) {
	return (LPC_TIM(timer_num)->IR &= (1 << mr_num));
}

/******************************************************************************
**                            End Of File
******************************************************************************/

/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include <stdbool.h>
#include "LPC17xx.h"
#include "timer.h"

#define MAX_TIMER_PROC 8

void (*TIMER0_funct[4][MAX_TIMER_PROC])(void);
void (*TIMER1_funct[4][MAX_TIMER_PROC])(void);
void (*TIMER2_funct[4][MAX_TIMER_PROC])(void);
void (*TIMER3_funct[4][MAX_TIMER_PROC])(void);

void assign_timer_function(uint8_t timer_num, uint8_t mr_num, void (*funct)(void)) {
	static uint8_t tim0_i[4] = {0,0,0,0}, tim1_i[4] = {0,0,0,0}, tim2_i[4] = {0,0,0,0}, tim3_i[4] = {0,0,0,0};
	
	switch(timer_num) {
		case TIMER0:
			if(tim0_i[mr_num] < MAX_TIMER_PROC)
				TIMER0_funct[mr_num][tim0_i[mr_num]++] = funct;
			break;
		case TIMER1:
			if(tim1_i[mr_num] < MAX_TIMER_PROC)
				TIMER1_funct[mr_num][tim1_i[mr_num]++] = funct;
			break;
		case TIMER2:
			if(tim2_i[mr_num] < MAX_TIMER_PROC)
				TIMER2_funct[mr_num][tim2_i[mr_num]++] = funct;
			break;
		case TIMER3:
			if(tim3_i[mr_num] < MAX_TIMER_PROC)
				TIMER3_funct[mr_num][tim3_i[mr_num]++] = funct;
			break;
	}
}

/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER0_IRQHandler (void) {
	uint8_t i;
	
	int8_t MR_handler = -1;
	if(MR_interrupt(TIMER0, MR0_TIM))
		MR_handler = MR0_TIM;
	
	if(MR_interrupt(TIMER0, MR1_TIM))
		MR_handler = MR1_TIM;
	
	if(MR_interrupt(TIMER0, MR2_TIM))
		MR_handler = MR2_TIM;
	
	if(MR_interrupt(TIMER0, MR3_TIM))
		MR_handler = MR3_TIM;
	
	for(i = 0; i < MAX_TIMER_PROC; i++) {
		if(TIMER0_funct[MR_handler][i] != 0)
			TIMER0_funct[MR_handler][i]();
	}
	
  LPC_TIM0->IR = 0x3F;
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void) {
	uint8_t i;
	int8_t MR_handler = -1;
	if(MR_interrupt(TIMER1, MR0_TIM))
		MR_handler = MR0_TIM;
	else if(MR_interrupt(TIMER1, MR1_TIM))
		MR_handler = MR1_TIM;
	else if(MR_interrupt(TIMER1, MR2_TIM))
		MR_handler = MR2_TIM;
	else if(MR_interrupt(TIMER1, MR3_TIM))
		MR_handler = MR3_TIM;
	
	for(i = 0; i < MAX_TIMER_PROC; i++) {
		if(TIMER1_funct[MR_handler][i] != 0)
			TIMER1_funct[MR_handler][i]();
	}
	
  LPC_TIM1->IR = 0x3F;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void TIMER2_IRQHandler (void) {
	uint8_t i;
	int8_t MR_handler = -1;
	if(MR_interrupt(TIMER2, MR0_TIM))
		MR_handler = MR0_TIM;
	else if(MR_interrupt(TIMER2, MR1_TIM))
		MR_handler = MR1_TIM;
	else if(MR_interrupt(TIMER2, MR2_TIM))
		MR_handler = MR2_TIM;
	else if(MR_interrupt(TIMER2, MR3_TIM))
		MR_handler = MR3_TIM;
	
	for(i = 0; i < MAX_TIMER_PROC; i++) {
		if(TIMER2_funct[MR_handler][i] != 0)
			TIMER2_funct[MR_handler][i]();
	}
	
  LPC_TIM2->IR = 0x3F;
  return;
}


/******************************************************************************
** Function name:		Timer3_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER3_IRQHandler (void) {
	uint8_t i;
	int8_t MR_handler = -1;
	if(MR_interrupt(TIMER3, MR0_TIM))
		MR_handler = MR0_TIM;
	else if(MR_interrupt(TIMER3, MR1_TIM))
		MR_handler = MR1_TIM;
	else if(MR_interrupt(TIMER3, MR2_TIM))
		MR_handler = MR2_TIM;
	else if(MR_interrupt(TIMER3, MR3_TIM))
		MR_handler = MR3_TIM;
	
	for(i = 0; i < MAX_TIMER_PROC; i++) {
		if(TIMER3_funct[MR_handler][i] != 0)
			TIMER3_funct[MR_handler][i]();
	}
	
  LPC_TIM3->IR = 0x3F;			/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

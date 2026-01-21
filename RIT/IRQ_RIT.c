/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"

#define MAX_RIT_PROC 16

static void (*RIT_funct[MAX_RIT_PROC])(void);

void assign_rit_function(void (*funct)(void)) {
	static int i = 0;
	
	if(i < MAX_RIT_PROC)
		RIT_funct[i++] = funct;
}

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

void RIT_IRQHandler (void){
	
	LPC_SC->EXTINT &= (1 << 0); /* clear pending interrupt         */
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/

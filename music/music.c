#include "LPC17xx.h"
#include "stdbool.h"
#include "music.h"

//void playNote(NOTE note)
//{
//	disable_mcr_interrupt(TIMER2, MCR0);
//	disable_mcr_interrupt(TIMER2, MCR1);
//	enable_mcr_interrupt(TIMER2, MCR2);
//	init_timer(TIMER3, note.freq, 0, 0, 0);
//	init_timer(TIMER2, 0, 0, note.duration, 0);
//	
//	if(note.freq != pause) {
//		reset_timer(TIMER3);
//		enable_timer(TIMER3);
//	}
//	reset_timer(TIMER2);
//	enable_timer(TIMER2);
//}

bool isNotePlaying(void)
{
	return ((LPC_TIM3->TCR & 1) == 1);
}

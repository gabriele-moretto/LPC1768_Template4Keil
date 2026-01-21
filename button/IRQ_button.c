#include "button.h"
#include "LPC17xx.h"

#define MAX_BUTTON_PROC 8

static void (*EINT_funct[3][MAX_BUTTON_PROC])(void);

static uint8_t butt_i[3] = {0, 0, 0};

void assign_button_function(uint8_t button_num, void (*funct)(void)) {
	if(butt_i[button_num] < MAX_BUTTON_PROC)
		EINT_funct[button_num][butt_i[button_num]++] = funct;
}

void remove_button_function(uint8_t button_num, void (*funct)(void)) {
	uint8_t i;
	
	i = 0;
	while(i < butt_i[button_num]) {
		if(EINT_funct[button_num][i] == funct) {
			butt_i[button_num]--;
			while(i < (MAX_BUTTON_PROC - 2)) {
				EINT_funct[button_num][i] = EINT_funct[button_num][i+1];
				i++;
			}
		} else if(EINT_funct[button_num][i] == 0) {
			break;
		}
	}
}

void remove_all_button_function(uint8_t button_num, void (*funct)(void)) {
	uint8_t i = 0;
	
	while(i < butt_i[button_num])
		EINT_funct[button_num][i++] = 0;
}

void EINT0_IRQHandler (void) {
	uint8_t i;
	disable_button_interrupt(BUTTON0);
	
	for(i = 0; i < MAX_BUTTON_PROC; i++) {
		if(EINT_funct[0][i] != 0)
			EINT_funct[0][i]();
	}
	
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}

void EINT1_IRQHandler (void){
	uint8_t i;
	disable_button_interrupt(BUTTON1);
	
	for(i = 0; i < MAX_BUTTON_PROC; i++) {
		if(EINT_funct[1][i] != 0)
			EINT_funct[1][i]();
	}
	
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void){
	uint8_t i;
	disable_button_interrupt(BUTTON2);
	
	for(i = 0; i < MAX_BUTTON_PROC; i++) {
		if(EINT_funct[2][i] != 0)
			EINT_funct[2][i]();
	}
	
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}



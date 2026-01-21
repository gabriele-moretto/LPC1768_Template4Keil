#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "LPC17xx.h"
#include "button.h"
#include "joystick.h"
#include "timer.h"
#include "rit.h"
#include "led.h"

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

#define MAX_VALUES 20
#define F_OSCILLATOR 4e6

#define DEBOUNCE_TIME 50e-3
#define DEBOUNCE_TICK (DEBOUNCE_TIME * F_OSCILLATOR/4)

void init_pheriperals(void);
void button0_handler(void);
void button0_handler2(void);
void button1_handler(void);
void timer0_handler(void);
	
char vector[MAX_VALUES];
uint8_t i;

int main() {
	init_pheriperals();
	
	while(1);
	return 0;
}

void init_pheriperals(void) {
	SystemInit();
	init_button();
	init_led();
	init_timer(TIMER1, 0xFF, 0, 0, 0);
	init_timer(TIMER0, DEBOUNCE_TICK, 0, 0, 0); 
	
	set_button_priority(BUTTON0, 1);
	set_button_priority(BUTTON1, 1);
	enable_button_interrupt(BUTTON0);
	enable_button_interrupt(BUTTON1);
	
	disable_timer_interrupt(TIMER1);
	disable_stop_on_match(TIMER1, MR0_TIM);
	enable_reset_on_match(TIMER1, MR0_TIM);
	
	enable_timer_interrupt(TIMER0);
	enable_interrupt_on_match(TIMER0, MR0_TIM);
	enable_reset_on_match(TIMER0, MR0_TIM);
	enable_stop_on_match(TIMER0, MR0_TIM);
	
	enable_timer(TIMER1);
	
	assign_button_function(BUTTON0, &button0_handler);
	assign_button_function(BUTTON1, &button1_handler);
	assign_timer_function(TIMER0, MR0_TIM, &timer0_handler);
}

void button0_handler(void) {
	static bool flag = false;
	char value;
	
	value = (char)get_timer_counter(TIMER1);
	if(i < MAX_VALUES) {
		vector[i] = value;
		i++;
	}
	
	if(!flag) {
		LED_On(6);
		LED_Off(7);
		flag = !flag;
	} else {
		LED_On(7);
		LED_Off(6);
		flag = !flag;
	}
	
	remove_button_function(BUTTON0, button0_handler);
	assign_button_function(BUTTON0, button0_handler2);
	enable_timer(TIMER0);
}

void button0_handler2(void) {
	LED_On(1);
}

void button1_handler(void) {
	LED_Off(6);
	LED_Off(7);

	LED_On(11);
	
	enable_timer(TIMER0);
}

void timer0_handler(void) {
	enable_button_interrupt(BUTTON0);
	enable_button_interrupt(BUTTON1);
}
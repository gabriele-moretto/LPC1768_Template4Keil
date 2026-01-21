#include "button.h"
#include "LPC17xx.h"

static bool butt_en[3] = {false, false, false};

int EINT_IRQn(uint8_t button_num) {
	switch(button_num) {
		case BUTTON0:
			return EINT0_IRQn;
			break;
		case BUTTON1:
			return EINT1_IRQn;
			break;
		case BUTTON2:
			return EINT2_IRQn;
			break;
	}
	return EINT0_IRQn;
}

/**
 * @brief  Function that initializes Buttons
 */
void init_button(void) {

  LPC_PINCON->PINSEL4    |= (1 << 20);		 /* External interrupt 0 pin selection */
  LPC_PINCON->PINSEL4    &= ~(1 << 21);

  LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
  LPC_PINCON->PINSEL4    &= ~(1 << 23);
  
  LPC_PINCON->PINSEL4    |= (1 << 24);     /* External interrupt 0 pin selection */
  LPC_PINCON->PINSEL4    &= ~(1 << 25);

  LPC_SC->EXTMODE = 0x7;                   /* Level-sensitivity is selected for external interrupts */
  LPC_SC->EXTPOLAR = 0;                    /* External interrupts are low-active or falling-edge sensitive */
}

bool button_interrupt_state(uint8_t button_num) {
	return (bool)NVIC_GetEnableIRQ(EINT_IRQn(button_num));
}

bool button_enable(uint8_t button_num) {
	return butt_en[button_num];
}

void disable_button_interrupt(uint8_t button_num) {
	NVIC_DisableIRQ(EINT_IRQn(button_num));
	butt_en[button_num] = false;
	return;
}

void enable_button_interrupt(uint8_t button_num) {
	NVIC_EnableIRQ(EINT_IRQn(button_num));
	butt_en[button_num] = true;
	return;
}

void set_button_priority(uint8_t button_num, uint8_t priority) {
	NVIC_SetPriority(EINT_IRQn(button_num), priority);
	return;
}

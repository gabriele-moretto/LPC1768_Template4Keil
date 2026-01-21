#include "joystick.h"

/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           funct_joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        High level joystick management functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

void joystick_init(void) {
  LPC_PINCON->PINSEL3 &= ~(3<<18);	//SEL Joystick pin
	LPC_PINCON->PINSEL3 &= ~(3<<22);	//Right Joystick pin
	LPC_PINCON->PINSEL3 &= ~(3<<24);	//Left Joystick pin
	LPC_PINCON->PINSEL3 &= ~(3<<26);	//Up Joystick pin
	
	LPC_GPIO1->FIODIR &= ~(1<<25);	//P1.25 Input
	LPC_GPIO1->FIODIR &= ~(1<<27);	//P1.27 Input
	LPC_GPIO1->FIODIR &= ~(1<<28);	//P1.28 Input
	LPC_GPIO1->FIODIR &= ~(1<<29);	//P1.29 Input
}

bool joystick_down() {
	return !(LPC_GPIO1->FIOPIN & (1<<26));
}

bool joystick_left() {
	return !(LPC_GPIO1->FIOPIN & (1<<27));
}

bool joystick_right() {
	return !(LPC_GPIO1->FIOPIN & (1<<28));
}

bool joystick_up() {
	return !(LPC_GPIO1->FIOPIN & (1<<29));
}

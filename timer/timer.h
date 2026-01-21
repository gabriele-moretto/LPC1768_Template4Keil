/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           timer.h
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        Prototypes of functions included in the lib_timer, funct_timer, IRQ_timer .c files
** Correlated files:    lib_timer.c, funct_timer.c, IRQ_timer.c
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef __TIMER_H
#define __TIMER_H

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#define TIMER3 3

#define MR0_TIM 0
#define MR1_TIM 1
#define MR2_TIM 2
#define MR3_TIM 3

/* init_timer.c */
void init_timer ( uint8_t timer_num, uint32_t t_MR0, uint32_t t_MR1, uint32_t t_MR2, uint32_t t_MR3);
extern void enable_timer( uint8_t timer_num );
extern void disable_timer( uint8_t timer_num );
extern void reset_timer( uint8_t timer_num );
extern void disable_timer_interrupt(uint8_t timer_num);
extern void enable_timer_interrupt(uint8_t timer_num);
void disable_interrupt_on_match(uint8_t timer_num, uint8_t mr_num);
void enable_interrupt_on_match(uint8_t timer_num, uint8_t mr_num);
extern void disable_reset_on_match(uint8_t timer_num, uint8_t mr_num);
extern void enable_reset_on_match(uint8_t timer_num, uint8_t mr_num);
extern void disable_stop_on_match(uint8_t timer_num, uint8_t mr_num);
extern void enable_stop_on_match(uint8_t timer_num, uint8_t mr_num);
uint32_t get_timer_counter(uint8_t timer_num);
bool MR_interrupt(uint8_t timer_num, uint8_t mr_num);

/* IRQ_timer.c */
void assign_timer_function(uint8_t timer_num, uint8_t mr_num, void (*funct)(void));
extern void TIMER0_IRQHandler (void);
extern void TIMER1_IRQHandler (void);
extern void TIMER2_IRQHandler (void);
extern void TIMER3_IRQHandler (void);

#endif /* end __TIMER_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/

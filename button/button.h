#include <stdint.h>

#define BUTTON0 0
#define BUTTON1 1
#define BUTTON2 2

#define KEY0 BUTTON0
#define KEY1 BUTTON1
#define KEY2 BUTTON2

void init_button(void);
bool button_interrupt_state(uint8_t button_num);
void disable_button_interrupt(uint8_t button_num);
void enable_button_interrupt(uint8_t button_num);
void set_button_priority(uint8_t button_num, uint8_t priority);
void remove_all_button_function(uint8_t button_num, void (*funct)(void));

void assign_button_function(uint8_t button_num, void (*funct)(void));
void remove_button_function(uint8_t button_num, void (*funct)(void));
void EINT1_IRQHandler(void);
void EINT2_IRQHandler(void);
void EINT3_IRQHandler(void);


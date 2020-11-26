#ifndef switches_included
#define switches_included
#define SWITCHES (SW1 | SW2 | SW3 | SW4)
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3

void switch_init();
void switch_interrupt_handler();

extern char switch_down;
extern char switch_state;
extern char s1, s2, s3, s4;
//extern char state;

#endif

#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachine.h"

char state;
char switch_state;
char switch_down;

void init_switch()
{
  P2REN |= SWTICHES;

  P2IE |= SWITCHES;

  P2OUT |= SWITCHES;

  P2DIR &= ~SWITCHES;

  change_interrupt_switch();
  interrupt_handler();

}
void interrupt_handler()
{
  char valp2 = change_interrupt_switch();

  if(valp2 & SW1 ? 0 : 1){
    state = 1;
  }

  else if(valp2 & SW2 ? 0 : 1){
    state = 2;
  }

  else if(valp2 & SW3 ? 0 : 1){
    state = 3;
  }
  else if(valp2 & SW4 ? 0 : 1){
    state = 4;
  }

  next_state();
}
static char change_interrupt_switch()
{
  
  char valp2 = P2IN;
  P2IES |= (valp2 & SWITCHES);
  P2IES &= (valp2 | ~SWITCHES);
  
  return valp2;
}

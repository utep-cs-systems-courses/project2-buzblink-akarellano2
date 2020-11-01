#include <msp430.h>
#include "stateMachine.h"

void
{
  __interrupt_vec(WDT_VECTOR) WDT() { //250 SEC

    static char counter; //counter for blink

    if(counter++ == 125) {
      next_state(); // will make sure it goes to next state //state_advance

      counter = 0;
    }
  }

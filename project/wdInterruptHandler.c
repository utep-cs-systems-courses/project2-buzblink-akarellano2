#include <msp430.h>
#include "stateMachine.h"

char switch_state_changed;
void
{
  __interrupt_vecc(WDT_VECTOR) WDT(){ /*250 interrupts per second */

    static char blink_count = 0;

    if(switch_state == 4){
      switch(switch_state_changed){
	
      case 4:
	
	if(++count < 62){
	  dim25();
	}
	else if(++count < 125){
	  dim25();
	}
	else if(++count == 250){
	  count = 0;
	}
	else{
	  dim75();
	}
	break;
      }
    }
    if(++blink_count == 125){
      state_advance();
      blink_count 0;
    }
  }

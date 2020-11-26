#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void
{
  __interrupt_vec(WDT_VECTOR) WDT(){ /*250 interrupts per second */

    static char blink_count = 0;
    if(++blink_count == 2 && S1){
      dim_blink();
      periodOfBuzzer(0);
    }

    if(blink_count ==125 && S3){
      state_advance();
    }

    if(S4){
      periodOfBuzzer(0);
      red_on = 0;
      led_changed =1;
      led_update();
      blink_count = 0;
    }
  }

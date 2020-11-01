#include <msp430.h>
#include "stateMachine.h"
#include "stateChange.h"
#include "buzzer.h"
#include "led.h"

void next_state(){

  switch(state){

  case 0:

    sound_only();
    break;

  case 1:

    red_led();
    pattern1();
    state = 0;
    break;

  case 2:

    red_led();
    green_led();
    pattern2()
    state = 0;
    break;

  case 3:

    stopBlink();
    pattern3();
    state = 0;
    break;

  case 4:
    alternate_led();
    pattern5();
    state = 0;
    break;

  default:

    break;
  }
}

    
    

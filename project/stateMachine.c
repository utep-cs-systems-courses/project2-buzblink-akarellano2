#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

static char button_pressed;
static char state = 0;
char toggle_red() //will always be on, red led
{
  static char state = 0;

  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char toggle_green() //will be on if the red one is on
{
  char changed = 0;
  if(red_on) {
    green_on ^=  1;
    changed = 1;
  }
  return changed;
}


char only_green() // will only turn on green led
{
  static char num = 0; // will determine if on and off
  switch(num){

  case 0:
    green_on = 1;
    num = 1; //meaning led on
    break;

  case 1:
    green_on = 0; // led off
    num = 0;
    break;
  }
  return 1; // letting know it was activated
}

char alternate_led() // will alternate between Red and Green led
{
  char changed = 0;
  static enum {R = 0, G=1} color = G;
  switch(color){
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  led_changed = changed;
  led_update();
}

char dim_lights()
{
  static char state = 0;
  switch(state){
    case 0:
      red_on = 1;
      led_changed = 1;
      led_update();
      state = 1;
      break;
    case 1:
      dim25();
      dim25();
      dim25();
      dim25();
      state = 2;
      break;
    case 2:
      toggle_red();
      toggle_red();
      state = 3;
      break;
    case 3:
      dim75();
      dim75();
      dim75();
      dim75();
      state = 0;
      break;
  }
  return 1;
}

void dim25()
{
  switch(state){
  case 0:
    red_on = 0;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 2;
    break;
  case 2:
    red_on = 0;
    state = 3;
    break;
  case 3:
    red_on = 1;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void dim75()
{
  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 1;
    state = 2;
    break;
  case 2:
    red_on = 1;
    state = 3;
    break;
  case 3:
    red_on = 1;
    state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
	    
void state_advance() //switching between states

{
  char changed = 0;
  switch(switch_state){
  case 1:
    changed = only_green();
    break;
  case 2:
    changed = alternate_led();
    break;
  case 3:
    changed = toggle_red();
    break;
  case 4:
    changed = dim_lights();
    break;
  }
  
  led_changed = changed; //making sure led has changed to next state
  led_update();
  
}

  
/*
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
    pattern2();
    state = 0;
    break;

  case 3:

    stopBlink();
    pattern3();
    state = 0;
    break;

  case 4:
    alternate_led();
    pattern4();
    state = 0;
    break;

  default:

    break;
    }*/


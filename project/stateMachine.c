#include <msp430.h> 
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static char dim_select = 0;
static char dimState = 0;
static char do_dim =  0;

char toggle_green() //green will blink only
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
char red_blink() // red light will blink
{
  static char state = 0;
  switch(state){

  case 0:
    green_on = 1;
    // red_on = 0;
    state = 1;
    break;
  case 1:
    // green_on = 0;
    green_on = 0;
    state = 0;
    break;
  }
  return 1;
}

char alternate(){ // switch between both
  char changed = 0;
  static enum {R = 0, G = 1} color = G;
  switch(color){
  case R: changed = red_blink(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  led_changed = changed;
  led_update();
}

void dim25(){
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 0;
    dimState = 1;
    break;
  case 1:
    red_on = 0;
    dimState = 2;
    break;
  case 2:
    red_on = 0;
    dimState = 3;
  case 3:
    red_on = 1;
    dimState = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void dim50(){
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 0;
    dimState = 2;
    break;
  case 2:
    red_on = 1;
    dimState = 3;
    break;
  case 3:
    red_on = 0;
    dimState = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

void dim75(){
  static char dimState = 0;
  switch(dimState){
  case 0:
    red_on = 1;
    dimState = 1;
    break;
  case 1:
    red_on = 1;
    dimState = 2;
    break;
  case 2:
    red_on = 1;
    dimState = 3;
    break;
  case 3:
    red_on = 0;
    dimState = 0;
    break;
  }
  led_changed = 1;
  led_update();
}

char dimLights() // dim state advnace
{
  //static char dim_select = 0;
  switch(dim_select){
  case 0:
    red_on = 0;
    led_changed = 1;
    led_update();
    dim_select = 1;
    break;
  case 1:
    dim25();
    dim25();
    dim25();
    dim25();
    dim_select = 2;
    break;
  case 2:
    dim50();
    dim50();
    dim_select = 3;
    break;
  case 3:
    dim75();
    dim75();
    dim75();
    dim75(); 
    dim_select = 0;
    break;
  }
  return 1;
}
/*
char dimLights()
{
  static char dim = 0;
  switch(dim){
  case 0:
    dim25();
    dim = 1;
    break;

  case 1:
    dim50();
    dim = 2;
    break;

  case 2:
    dim75();
    dim =  0;
    break;

  default:
    red_on = 0;
    green_on = 0;
    dim = 0;
    break;
  }
  return 1;
}
*/

void state_advance(){
  char changed = 0;
  switch(switch_state_changed){
  
  case 1:
    changed = alternate();
    break;
  case 2:
    changed = red_blink();
    break;
  case 3:
    changed = toggle_green();
    break;
  case 4:
    // changed = 1;
    changed = dimLights();
    break;
  }
  led_changed = changed;
  led_update();
}



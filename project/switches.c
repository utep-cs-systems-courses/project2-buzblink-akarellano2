#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "libTimer.h"

//char state;
char switch_down;
char switch_state;
char s1, s2, s3, s4;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);

  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();
  led_update();

}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  s1 = (p2val & SW1) ? 0 : 1;
  s2 = (p2val & SW2) ? 0 : 1;
  s3 = (p2val & SW3) ? 0 : 1;
  s4 = (p2val & SW4) ? 0 : 1;

  if(s1){
    switch_down = s1;
    switch_state = 1;
    led_update();
    pattern1();
  }

  else if(s2){
    switch_down = s2;
    switch_state = 2;
    led_update();
    pattern2();
  }
  else if(s3){
    switch_down = s3;
    switch_state = 3;
    led_update();
    pattern3();
  }
  else if(s4){
    switch_down = s4;
    switch_state = 4;
    led_update();
    pattern4();
  }
  switch_state = 1;
  led_update();
}

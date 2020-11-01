#include <msp430.h>
#include "led.h"
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"

void red_led()
{
  int i;
  for(i = 0;i < 10; i++){

    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);

  }
}

void green_led()
{
  int i;
  for(i = 0; i < 10; i++){

    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

void led_init()
{
  P1DIR |= LEDS;
  switch_state = 1;
}

void turnOff()
{
  int i;

  for(i = 0; i < 10000; i++){
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

void stopBlink()
{
  int i;

  for(i = 0; i < 20; i++){

    turnOff();
    __delay_cycles(2000000);
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

void alternate_led()
{
  int i;

  for(i = 0; i < 10; i++){

    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

void change_led()
{

  if(switch_state){

    char flags = 0;
    flags |= swtich_down ? LED_RED : 0;
    flags |= switch_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | flags;
    P1OUT |= flags;

  }

  switch_state = 0;
}

void

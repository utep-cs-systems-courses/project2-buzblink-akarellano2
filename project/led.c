#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

unsigned char red_on = 0; //red light off
unsigned char green_on = 0; // green light off

static char redVal[] = {0, LED_RED};
static char greenVal[] = {0, LED_GREEN};

unsigned char led_changed = 0; /* if light changes it should be 1 */

/*
void green_led() // greenLigths
{
  int i;
  for(i = 0; i<10; i++){
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

void red_led() // redLights
{
  int i;
  for(i = 0; i<10; i++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    P1OUT = !LED_RED;
    __delay_cycles(800000);
  }
}
*/
  
void led_init()
{
  P1DIR |= LEDS; // bits are connected to output
  led_changed = 1;
  led_update();
}

void led_update() /*will clear everything*/
{
  if(led_changed){ // if led_changed = 1
    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff^LEDS) | ledFlags; //clearing bits
    P1OUT |= ledFlags; // set bits
    led_changed = 0;
  }
}


 /*
void led_update() /*clears everything for it to start it over
{
  if(switch_state){

    char flags = 0;

    flags |= switch_down ? LED_RED : 0;
    flags |= switch_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | flags;
    P1OUT |= flags;
  }
  switch_state = 0;
}
/*
void dimBlink()  //stopBlink
{
  int i;
  for(i = 0; i<20;i++){
    turnOff();
    __delay_cycles(2000000);
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
  }*/
/*
void dimLights() // dimLights method //turnOff
{
  int i;
  for(i = 0; i<10000; i++){
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
  }*/
/*
void alternate_led() //bothLights method
{
  for(int i = 0; i < 15; i++){
    P1OUT = LED_RED;
    __delay_cycles(800000);

    P1OUT = LED_GREEN;
    __delay_cycles(800000);

    P1OUT = !LED_RED;
    __delay_cycles(800000);

    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
  }*/


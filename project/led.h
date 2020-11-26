#ifndef led_included
#define led_included
#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

//methods
void led_init();

void led_update();

/*
void dimLights();

void green_led();

void red_led();

void alternate_led();

void dimBlink();


extern unsigned char green_led_state;

extern unsigned char red_led_state;
*/

extern unsigned char red_on, green_on, led_changed;

#endif

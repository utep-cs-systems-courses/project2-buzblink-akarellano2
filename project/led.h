#ifndef led_included
#define led_included
#include <msp430.h>
#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on;
extern unsigned char green_on;
extern unsigned char led_changed;

void led_init();

void led_update();
/*
void dimLights();

void green_led();

void red_led();

void alternate_led();

void dimBlink();
*/
extern unsigned char green_led_state;

extern unsigned char red_led_state;

#endif

#ifndef led_included
#define led_included
#include <msp430.h>
#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

void led_init();

void change_led();

void turnOff();

void green_led();

void red_led();

void alternate_led();

void stopBlink();

extern unsigned char leds_changed;

extern unsigned char green_led_state;

extern unsigned char red_led_state;

#endif

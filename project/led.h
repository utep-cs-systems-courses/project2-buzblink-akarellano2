#ifndef led_included
#define led_included
#include <msp430.h>
#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT0 | BIT6)

void red_led();

void green_led();

void led_init();

void change_led();

void turnOff();

void alternate_led();

void stopBlink();

extern unsigned char leds_changed, green_led_state, red_led_state;

#endif

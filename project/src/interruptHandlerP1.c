#include <msp430.h>
#include "buzzer.h"
#include "switches.h"
#include "led.h"
#include "libTimer.h"

void main(void)
{
  configureClocks();
  init_buzzer();
  init_switch();
  led_init();
  enableWDTInterrupts();
  or_sr(0x18);
}

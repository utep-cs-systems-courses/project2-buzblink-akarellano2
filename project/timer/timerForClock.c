#include <msp430.h>
#include "timerLib.h"

void configureClock()
{
  WDTCTL = WDTPW + WDDTHOLD;
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;

  BCSCTL2 &= ~(SELS);
  BCSCCTL2 |=  DIVS_3;

}

void enableWdTInterrupts()
{
  WWDTCTL = WDTPW |
    WDTTMSEL |
    WDTCNTCL |
    1;

  IE1 |= WDTIE;

}

void timerAUpmode()
{
  TA0CCR0 = 0;
  TA0CCR1 = 0;
  TA0CCTL1 = OUTMOD_3;

  TACTL = TASSEL__2 + MC_1;
}

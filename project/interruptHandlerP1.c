#include <msp430.h>
#include "stateChange.h"

void
{
  __interrupt_vec(PORT2_VECTOR) Port_2(){

    if(P2IFG & SWTICHES){
      P2IFG &= ~SWITCHES;

      swtich_interrupt_handler();
    }
  }

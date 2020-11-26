#include "libTimer.h"
#include "buzzer.h"
#include <msp430.h>

/*Defining notes to bee used with their frequency */
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012

void periodOfBuzzer(short cycle) //buzzer clock 
{
  
  CCR0 = cycle;
  CCR1 = cycle >> 1; //half cycle
}

void init_buzzer()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~ BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void pattern1()
{
  
  int letters[] = {C4,0,D4,0,F4,0,G4,0,B4,0};

  int i;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    periodOfBuzzer(letters[i]);
    state_advance();
    i++;
  }
}
  /*
  for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){

    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000); //between each cycle
    }*/

void pattern2()
{

  int letters[] = {B4, 0, A4, 0, G4, 0, B4, 0, A4, 0, G4, 0};

  int i;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    periodOfBuzzer(letters[i]);
    state_advance();
    i++;
  }
  /*
  for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}

void pattern3()
{

  int letters[] = {E4, 0, D4, 0, E4, 0, F4, 0, G4, 0, F4, 0, G4, 0, A4, 0, B4, 0, B4,0, B4, 0};

  int i;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    periodOfBuzzer(letters[i]);
    state_advance();
    i++;
  
  /* for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}
}

void pattern4()
{

  int letters[] = {F4, 0, A4, 0, G4, 0, F4, 0, E4, 0, D4, 0, C4, 0};

  int i;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    periodOfBuzzer(letters[i]);
    state_advance();
    i++;
  } 
  /* for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}

void sound_only()
{
  int letters[] = {D4, 0};
  int i;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    periodOfBuzzer(letters[i]);
    state_advance();
    i++;
  }
}
  /*
  for(i =0; i<sizeof(letter)/sizeof(*letter); i++){
    periodOfBuzzer(letter[i]);
    __delay_cycles(1200000);
    }*/


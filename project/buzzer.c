#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

/*Defining notes to bee used with their frequency */
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012

void init_buzzer() // initialize buzzer
{
  timerAUpmode(); //speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~ BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //output to speaker
}

void buzzer_set_period(short cycles) //buzzer clock 
{
  
  CCR0 = cycles;
  CCR1 = cycles >> 1; //half cycle
}


void pattern1() //first song
{
  
  int letters[] = {C4,D4,F4,G4,B4}; //notes of song

  int i = 0;
  while(i <sizeof(letters)){ // move across notes
    int count = 0;
    while(count < 20){
      int count2 = 0;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    buzzer_set_period(letters[i]);
    state_advance();
    i++;
  }
}
  /*
  for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){

    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000); //between each cycle
    }*/

void pattern2() // song 2
{

  int letters[] = {B4, A4, G4, B4, A4, G4};

  int i = 0;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2 = 0;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    buzzer_set_period(letters[i]);
    state_advance();
    i++;
  }
  /*
  for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}

void pattern3() // song 3 for state 3
{

  int letters[] = {E4, D4, E4, F4, G4, F4, G4, A4};

  int i = 0;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2 =0;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    buzzer_set_period(letters[i]);
    state_advance();
    i++;
  
  /* for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}
}

void pattern4() // song 4 for state 4
{

  int letters[] = {F4, A4, G4, F4, E4, D4, C4};

  int i = 0;
  while(i <sizeof(letters)){
    int count = 0;
    while(count < 20){
      int count2 = 0;
      while(count2 < 30000){
	count2++;
      }
      count++;
    }
    buzzer_set_period(letters[i]);
    state_advance();
    i++;
  } 
  /* for(i = 0; i < sizeof(letters)/sizeof(*letters); i++){
    periodOfBuzzer(letters[i]);
    __delay_cycles(1200000);
    }*/
}


#ifndef timer_included
#define timer_included

void configureClocks();
void enableWDTInterrupts();
void timerAUpmode();

unsigned char geert_sr();
void set_sr(), or_sr(), and _sr();

#endif

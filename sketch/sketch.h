#ifndef __SKETCHLIB_H__
#define __SKETCHLIB_H__

#define STARTING_LED 6

#define LED1 1
#define LED2 2
#define LED3 3
#define LED4 4

#define POT A0

#define BUTTON1 8
#define BUTTON2 9
#define BUTTON3 10
#define BUTTON4 11

#define STARTING_STATE 0
#define GAMING_STATE 1
#define END_STATE 2

extern volatile unsigned char state;
extern volatile int k;
extern volatile unsigned char score;
extern volatile unsigned char currentPosition;
extern volatile unsigned char tMin;
extern volatile unsigned long tPression;

#endif

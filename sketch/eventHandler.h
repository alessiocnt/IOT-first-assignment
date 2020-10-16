#ifndef __EVENTHANDLERLIB_H__
#define __EVENTHANDLERLIB_H__

/* public */
void button1Pressed();
void button2Pressed();
void button3Pressed();
void button4Pressed();
void eventHandlerReset();
static void startGame();
static void onPression(unsigned char button);
static bool preventBouncing();
static unsigned char nextPosition();

#endif

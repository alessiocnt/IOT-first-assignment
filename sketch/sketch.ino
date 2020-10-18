#include <EnableInterrupt.h>
#include "sketch.h"
#include "start.h"
#include "game.h"
#include "end.h"
#include "eventHandler.h"

int k;
volatile unsigned char state;
volatile unsigned char score;
volatile unsigned char currentPosition;
volatile unsigned char tMin;
volatile unsigned char tForMovement;
volatile unsigned long tPression;
volatile unsigned char leds[] = {LED1, LED2, LED3, LED4};

void setup() {
    pinMode(STARTING_LED, OUTPUT);
    pinMode(POT, INPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
    pinMode(BUTTON4, INPUT);

    Serial.begin(115200);

    enableInterrupt(BUTTON1, button1Pressed, RISING);
    enableInterrupt(BUTTON2, button2Pressed, RISING);
    enableInterrupt(BUTTON3, button3Pressed, RISING);
    enableInterrupt(BUTTON4, button4Pressed, RISING);

    state = STARTING_STATE;
    k = 15;
    score = 0;
}

void loop() {
    switch (state)
    {
    case STARTING_STATE:
        startingPhase();
        break;
    case GAMING_STATE:
        gamingPhase();
        break;
    case END_STATE:
        restartGame();
        break;
    }
    
}

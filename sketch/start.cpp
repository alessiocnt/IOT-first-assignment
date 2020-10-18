#include <arduino.h>
#include <stdbool.h>
#include "sketch.h"
#include "start.h"

static unsigned long previousTime = 0;
static unsigned char fadeAmount = 5;
static unsigned char currentIntensity = 0;
static bool firstCycle = true;

/* Manage the initial fading led and serial print */
void startingPhase() {
    if(firstCycle) {
        firstCycle = false;
        Serial.println("Welcome to the Track to Led Fly Game. Press Key T1 to Start.");
    }
    fade();
}

/* Let the stating led fade through multiple cycles */
void fade() {
    long timeStamp = micros();
    if(timeStamp - previousTime > 15000) {
        analogWrite(STARTING_LED, currentIntensity);
        currentIntensity += fadeAmount;
        if (currentIntensity == 0 || currentIntensity == 255) {
            fadeAmount = -fadeAmount ; 
        }   
        previousTime = timeStamp;
    }
}

/* Reset the game variables associated with this file */ 
void startReset() {
    previousTime = 0;
    fadeAmount = 5;
    currentIntensity = 0;
    firstCycle = true;
}

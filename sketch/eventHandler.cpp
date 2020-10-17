#include <arduino.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sketch.h"
#include "eventHandler.h"

static bool firstPression = true;

void button1Pressed() {
    tPression = millis();
    if(firstPression) {
        firstPression = false;
        startGame();
    } else {
        onPression(1);
    }
}

void button2Pressed() {
    tPression = millis();
    onPression(2);
}
void button3Pressed() {
    tPression = millis();
    onPression(3);
}
void button4Pressed() {
    tPression = millis();
    onPression(4);
}

/* Set the variable for the game.
    Start the game. */
void startGame() {
    static unsigned char levels[] = {8, 7, 6, 5, 4, 3, 2, 1};
    digitalWrite(STARTING_LED, LOW);
    k = analogRead(POT);
    k = map(k, 0, 1023, 0, 7);
    state = GAMING_STATE;
    currentPosition = rand() % 4 + 1;
    tMin = levels[k]*500;
    // tPression = millis();
    Serial.println("Go!");
}

/* Controls the pression of a button */
void onPression(unsigned char button) {
    if (!preventBouncing()) {
        return;
    }
    if (button != currentPosition) {
        state = END_STATE;
        return;
    }
    score++;
    Serial.println("Tracking the fly: pos " + currentPosition);
    currentPosition = nextPosition();
    tMin = tMin/2;
}

/* True if the button pression is correct 
    False if occurred bouncing */
bool preventBouncing() {
    static long prevts = 0;
    long ts = micros();
    if (ts - prevts > 20000){
        prevts = ts;
        return true;
    }
    return false;
}

/* Return a position near the current one */
unsigned char nextPosition() {
    int rnd = (rand() % 2 ? -1 : 1);
    if (currentPosition + rnd <= 0) {
        return 4;
    }
    return ((currentPosition + rnd) % 4) +1;
}

/* Reset the game variables */ 
void eventHandlerReset() {
    firstPression = true;
}

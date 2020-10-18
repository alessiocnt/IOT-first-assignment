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
    static unsigned char levels[] = {80, 70, 60, 50, 40, 30, 20, 10};
    static int level;
    digitalWrite(STARTING_LED, LOW);
    level = analogRead(POT);
    level = map(level, 0, 1023, 0, 7);
    state = GAMING_STATE;
    currentPosition = rand() % 4 + 1;
    digitalWrite(leds[currentPosition - 1], HIGH);
    tMin = levels[level];
    tForMovement = calculateTimeForMovement();
    // tPression = millis();
    Serial.println("Go!");
}

/* Controls the pression of a button */
void onPression(unsigned char button) {
    // Se sono nello stato sbagliato e premo un bottone non devo fare nulla
    if (!state == GAMING_STATE) {
      return;
    }
    if (!preventBouncing()) {
      return;
    }
    if (button != currentPosition) {
      digitalWrite(leds[currentPosition - 1], LOW);
      state = END_STATE;
      return;
    }
    score++;
    Serial.print("Tracking the fly: pos ");
    Serial.println(currentPosition);
    // Spengo il vecchio led e accendo quello nuovo
    digitalWrite(leds[currentPosition - 1], LOW);
    currentPosition = nextPosition();
    digitalWrite(leds[currentPosition - 1], HIGH);
    tMin = tMin/2;
    tForMovement = calculateTimeForMovement();
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
    int rnd = rand() % 2;   // rnd can be 0 or 1
    if (rnd == 0) {
        rnd = -1;
    }
    if (currentPosition == 4 && rnd == 1) {
        return 1;
    } else if (currentPosition == 1 && rnd == -1) {
        return 4;
    } else {
        return currentPosition + rnd;
    }
    
    /* int rnd = (rand() % 2 ? -1 : 1);
    if (currentPosition + rnd <= 0) {
        return 4;
    }
    return ((currentPosition + rnd) % 4) +1; */
}

/* Calculates the time needed to perform the next movement */
unsigned char calculateTimeForMovement() {
    return tMin + (rand() % (k * tMin - tMin + 1));
}

/* Reset the game variables */ 
void eventHandlerReset() {
    firstPression = true;
}

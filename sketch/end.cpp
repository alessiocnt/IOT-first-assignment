#include <arduino.h>
#include <stdbool.h>
#include "sketch.h"
#include "end.h"
#include "eventHandler.h"
#include "start.h"

static bool firstTimeIn = true;
static unsigned long previousTime = 0;

void restartGame() {
    if(firstTimeIn) {
        firstTimeIn = false;
        previousTime = millis();
        digitalWrite(STARTING_LED, HIGH);
        Serial.println("Game Over - Score: " + score);
        initialize();
    }
    endingLed();
}

void initialize() {
    startReset();
    eventHandlerReset();
    score = 0;
}

void endingLed() {
    long timeStamp = millis();
    if(timeStamp - previousTime > 2000) {
        digitalWrite(STARTING_LED, LOW);
        state = STARTING_STATE;
    }
}

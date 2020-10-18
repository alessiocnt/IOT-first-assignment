#include <arduino.h>
#include "sketch.h"
#include "game.h"
 
void gamingPhase() {
    digitalWrite(leds[currentPosition - 1], HIGH);
    if (millis() - tPression > tForMovement) {
        state = END_STATE;
    }
}

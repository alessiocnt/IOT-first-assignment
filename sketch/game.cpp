#include <arduino.h>
#include "sketch.h"
#include "game.h"
 
void gamingPhase() {
    digitalWrite(leds[currentPosition - 1], HIGH);
    // k*tMin
    if (millis() - tPression > 10000) {
        state = END_STATE;
    }
}

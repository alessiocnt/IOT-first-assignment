#include <arduino.h>
#include "sketch.h"
#include "game.h"
 
void gamingPhase() {
    digitalWrite(currentPosition, HIGH);
    unsigned long tNow = millis();
    if (tNow - tPression > (k+1)*tMin) {
        state = END_STATE;
    }
}

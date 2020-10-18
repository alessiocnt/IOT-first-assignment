#include <arduino.h>
#include "sketch.h"
#include "game.h"
 
void gamingPhase() {
    if (millis() - tPression >= 100 * tForMovement) {
        state = END_STATE;
    }
}

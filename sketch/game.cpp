#include <arduino.h>
#include "sketch.h"
#include "game.h"

/* Timer for one round of the game */
void gamingPhase() {
    if (millis() - tPression >= 100 * tForMovement) {
        state = END_STATE;
    }
}

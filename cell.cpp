#include "Cell.h"

int Cell::computeNextState(int currentState, int liveNeighbors) {
    if (currentState == ALIVE) {
        return (liveNeighbors == 2 || liveNeighbors == 3) ? ALIVE : DEAD;
    } else {
        return (liveNeighbors == 3) ? ALIVE : DEAD;
    }
}

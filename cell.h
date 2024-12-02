#ifndef CELL_H
#define CELL_H

class Cell {
public:
    static int computeNextState(int currentState, int liveNeighbors);

private:
    static const int ALIVE = 1;
    static const int DEAD = 0;
};

#endif // CELL_H

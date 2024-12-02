#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Cell.h"

class Grid {
public:
    Grid(const std::vector<std::vector<int>>& initialGrid);
    void computeNextGeneration();
    void displayGrid() const;
    bool isStable() const;

private:
    int countLiveNeighbors(int row, int col) const;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> previousGrid;
    int rows;
    int cols;
};

#endif // GRID_H

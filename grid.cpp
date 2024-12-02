#include "Grid.h"
#include <iostream>

Grid::Grid(const std::vector<std::vector<int>>& initialGrid)
    : grid(initialGrid), previousGrid(initialGrid), rows(initialGrid.size()), cols(initialGrid[0].size()) {}

void Grid::computeNextGeneration() {
    previousGrid = grid;
    std::vector<std::vector<int>> newGrid = grid;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int liveNeighbors = countLiveNeighbors(i, j);
            newGrid[i][j] = Cell::computeNextState(grid[i][j], liveNeighbors);
        }
    }

    grid = newGrid;
}

int Grid::countLiveNeighbors(int row, int col) const {
    int liveCount = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue; // Ignorer la cellule centrale

            int newRow = row + i;
            int newCol = col + j;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                liveCount += grid[newRow][newCol];
            }
        }
    }

    return liveCount;
}

void Grid::displayGrid() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? '1' : '0') << " ";
        }
        std::cout << std::endl;
    }
}

bool Grid::isStable() const {
    return grid == previousGrid; // Comparer la grille actuelle avec la grille précédente
}

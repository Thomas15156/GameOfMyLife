#include "openfile.h"
#include <iostream>
#include <fstream>

Grid::Grid() {}

void Grid::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> rows >> cols;
    grid.resize(rows, std::vector<int>(cols)); // Redimensionner la matrice

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> grid[i][j];
        }
    }

    file.close();
}

void Grid::displayGrid() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::runGameOfLife() {
    std::string filename;

    std::cout << "Entrez le nom du fichier :";
    std::cin >> filename;

    readFromFile(filename);
    displayGrid();
}
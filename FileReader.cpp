#include "FileReader.h"
#include <iostream>
#include <fstream>

FileReader::FileReader() {}

void FileReader::readFromFile() {
    std::cout << "Enter the file name :";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file >> rows >> cols;
    grid.resize(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> grid[i][j];
        }
    }

    file.close();
}

const std::vector<std::vector<int>>& FileReader::getGrid() const {
    return grid;
}

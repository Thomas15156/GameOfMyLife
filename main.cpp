#include "FileReader.h"
#include "Grid.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    FileReader fileReader;
    fileReader.readFromFile();

    Grid gameGrid(fileReader.getGrid());

    std::cout << "Initial generation: " << std::endl;
    gameGrid.displayGrid();


    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for 1 second
        std::cout << "Next Generation" << std::endl;
        gameGrid.computeNextGeneration();
        gameGrid.displayGrid();

        if (gameGrid.isStable()) {
            std::cout << "The grid is stable. Stopping simulation." << std::endl;
            break;
        }
    }

    return 0; // End the program (although this line won't be reached)
}

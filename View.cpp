#include "View.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

View::View(const std::vector<std::vector<int>>& grid) : grid(grid){}

void View::run_console() const
{
    for (auto row : grid) {
        for (auto cell : row) {
            std::cout << (cell ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }
}



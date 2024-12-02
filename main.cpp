#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "View.h"



int main() {
    const int gridWidth = 5;
    const int gridHeight = 5;

    std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));


    View view_graphics;
    view_graphics.init_grid(grid);
    view_graphics.run_graphics(grid);
    return 0;
}

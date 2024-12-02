#include "View.h"
#include "Model.h"
#include <iostream>

View::View(const Grid& grid) : grid(grid) {}


void View::view_run_console() const
{
    const auto& grid_temp = grid.get_grid();
    for (const auto& row : grid_temp)
    {
        for (int cell: row)
        {
            std::cout << cell << " ";
        }
        std::cout <<"\n";
    }
}




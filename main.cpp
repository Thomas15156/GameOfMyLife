#include <iostream>
#include <thread>

#include "Model.h"
#include "View.h"
#include "Controller.h"

int main() {
    int rows = 5;
    int cols = 5;

    Grid grid(rows, cols);

    // c'est pour les tests
    int initial_grid[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            grid.set_cell(i, j, initial_grid[i][j]);
        }
    }

    View view(grid);
    view.view_run_console();

    for (int cycle = 1; cycle < 10; cycle++)
    {


        Game_controller controller(grid, view);
        controller.calculate_next_generation();
        controller.rules();

        // afficher la matrice temporaire pour voir le nombre de voisins vivants
        /*std::cout << "Neighbors of the first cell:\n";
        const auto& grid_neighbors = controller.get_grid_neighbors();
        for (const auto& row : grid_neighbors)
        {
            for (int cell: row)
            {
                std::cout << cell << " ";
            }
            std::cout <<"\n";
        }
        */

        std::cout << "Next generation : " << cycle << " \n";
        view.view_run_console();

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

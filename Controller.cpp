#include "Controller.h"

Game_controller::Game_controller(Grid& grid, View& view) : grid(grid), view(view), grid_neighbors(grid.get_grid().size(), std::vector<int>(grid.get_grid()[0].size(), 0)){}

void Game_controller::calculate_next_generation()
{
    const auto& grid_temp = grid.get_grid();
    for (int x = 0; x < grid_temp[0].size(); x++)
    {
        for (int y = 0; y < grid_temp.size(); y++)
        {
            grid_neighbors[x][y] = neighbors_alive(x, y);
        }
    }
}

const std::vector<std::vector<int>>& Game_controller::get_grid_neighbors() const
{
    return grid_neighbors;
}

void Game_controller::rules()
{
    const auto& grid_temp = grid.get_grid();
    std::vector<std::vector<int>> new_grid = grid_temp;
    for (int x = 0; x < grid_temp[0].size(); x++)
    {
        for (int y = 0; y < grid_temp.size(); y++)
        {
            int alive_neighbors = grid_neighbors[x][y];
            if (grid_temp[x][y] == 1)
            {
                if (alive_neighbors < 2 || alive_neighbors > 3)
                {new_grid[x][y] = 0;}
            }else
            {
                if (alive_neighbors == 3)
                {new_grid[x][y] = 1;}
            }
        }
    }
    grid = Grid(new_grid[0].size(), new_grid.size());
    for (int x = 0; x < new_grid[0].size(); x++)
    {
        for (int y = 0; y < new_grid.size(); y++)
        {
            grid.set_cell(x, y, new_grid[x][y]);
        }
    }
}









int Game_controller::neighbors_alive(int x, int y) const
{
    int count = 0;
    const auto& grid_temp = grid.get_grid();
    for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < grid_temp[0].size() && ny >= 0 && ny < grid_temp.size())
            {
                count += grid_temp[nx][ny];
            }
        }
    }
    return count;
}

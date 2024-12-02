//
// Created by benjamin Bourlet on 28/11/2024.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include "View.h"


class Game_controller {
public:
    Game_controller(Grid& grid, View& view);
    void calculate_next_generation();
    const std::vector<std::vector<int>>& get_grid_neighbors() const;
    void rules();
private:
    Grid& grid;
    View& view;
    std::vector<std::vector<int>> grid_neighbors;
    int neighbors_alive(int x,int y) const;
};



#endif //CONTROLLER_H

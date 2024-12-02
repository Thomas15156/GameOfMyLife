//
// Created by benjamin Bourlet on 28/11/2024.
//

#include "Model.h"

#include <iostream>
#include <ostream>

Grid::Grid(int rows, int cols) : rows(rows), cols(cols), grid(rows, std::vector<int>(cols, 0)) {}


void Grid::set_cell(int row, int col, int value)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols)
    {
        grid[row][col] = value;
    }
}

const std::vector<std::vector<int>>& Grid::get_grid() const
{
    return grid;
}

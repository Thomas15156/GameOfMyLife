#ifndef MODEL_H
#define MODEL_H

#include <vector>

class Grid {
    private:
    int rows, cols;
    std::vector<std::vector<int>> grid;

    public:
    Grid(int rows, int cols);
    void set_cell(int row, int col, int value);
    const std::vector<std::vector<int>>& get_grid() const;

};

#endif // MODEL_H


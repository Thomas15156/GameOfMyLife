#ifndef VIEW_H
#define VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>

class View {
public:

    View(const std::vector<std::vector<int>>& grid);
    void run_console() const;
    void init_grid(std::vector<std::vector<int>>& grid);
    void run_graphics(const std::vector<std::vector<int>>& grid);

private:
    const std::vector<std::vector<int>>& grid;
    const int cellSize = 10;
    const int gridWidth = 5;
    const int gridHeight = 5;
};

#endif // VIEW_H

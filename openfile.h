#ifndef OPENFILE_H
#define OPENFILE_H

#include <vector>
#include <string>

class Grid {
public:
    Grid();
    void readFromFile(const std::string& filename);
    void displayGrid() const;
    void runGameOfLife();

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> grid;
};

#endif // OPENFILE_H
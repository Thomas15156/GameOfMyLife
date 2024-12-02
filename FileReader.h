#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>

class FileReader {
public:
    FileReader();
    void readFromFile();
    const std::vector<std::vector<int>>& getGrid() const;

private:
    std::string filename;
    int rows;
    int cols;
    std::vector<std::vector<int>> grid;
};

#endif // FILEREADER_H

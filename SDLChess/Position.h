#pragma once

#include <string>
#include <format>

class Position {
public:
    Position();
    Position(int squareIndexX, int squareIndexY);
    Position(int coordX, int coordY, int squareSize);

    std::string getDisplayString();
    int getIndex();

    bool operator==(Position other) {
        return file == other.file && rank == other.rank;
    }

    bool operator!=(Position other) {
        return !(*this == other);
    }

private:
    char file;
    int rank;
};
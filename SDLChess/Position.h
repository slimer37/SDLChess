#pragma once

#include <string>
#include <format>

struct Position {
    Position();
    Position(int squareIndexX, int squareIndexY);
    Position(int coordX, int coordY, int squareSize);

    std::string getDisplayString();

    int getIndex();

    bool isLight();

    /// <summary>
    /// Returns the file as an int, where A is 1.
    /// </summary>
    /// <returns></returns>
    int fileAsInt();

    bool operator==(Position other) {
        return file == other.file && rank == other.rank;
    }

    bool operator!=(Position other) {
        return !(*this == other);
    }

    char getFile() { return file; }
    int getRank() { return rank; }

private:
    char file;
    int rank;
};
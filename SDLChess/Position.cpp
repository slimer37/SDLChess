#include "Position.h"

#include <string>
#include <format>

Position::Position() : Position(0, 0) {}

Position::Position(int xIndex, int yIndex) :
    file('A' + xIndex), rank(yIndex + 1) {}

Position::Position(int coordX, int coordY, int squareSize) :
    Position(coordX / squareSize, coordY / squareSize) {}

std::string Position::getDisplayString() {
    return std::format("{}{}", file, rank);
}

int Position::getIndex() {
    return (rank - 1) * 8 + fileAsInt();
}

int Position::fileAsInt() {
    return file - 'A' + 1;
}

bool Position::isLight() {
    return (rank + fileAsInt()) % 2 == 0;
}
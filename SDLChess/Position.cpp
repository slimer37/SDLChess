#include "Position.h"

#include <string>
#include <format>

Position::Position() : Position(0, 0) {}

Position::Position(int xIndex, int yIndex) :
    file('A' + xIndex), rank(8 - yIndex) {}

Position::Position(int coordX, int coordY, int squareSize) :
    Position(coordX / squareSize, coordY / squareSize) {}

std::string Position::getDisplayString() {
    return std::format("{}{}", file, rank);
}

int Position::getIndex() {
    return (rank - 1) * 8 + (file - 'A');
}
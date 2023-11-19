#pragma once

#include "Position.h"

class Board {
    SDL_Renderer *renderer;
public:
    const int tileSize;

    Board(int tileSize);

    void render();
    void highlight(Position position);

    void setRenderer(SDL_Renderer *renderer);
};


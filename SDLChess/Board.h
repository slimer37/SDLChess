#pragma once

#include "Position.h"

class Board {
    SDL_Renderer *renderer;
public:
    const int tileSize;

    Board(int tileSize);

    /// <summary>
    /// Clears the buffer and renders an empty chess grid to the screen.
    /// </summary>
    void render();
    void highlight(Position position);

    void setRenderer(SDL_Renderer *renderer);
};


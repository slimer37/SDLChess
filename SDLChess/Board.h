#pragma once

class Board {
    SDL_Renderer *renderer;
public:
    void render();

    Board(int tileSize);

    void setRenderer(SDL_Renderer *renderer);

    const int tileSize;
};


#pragma once

class Board {
public:
    void render(SDL_Renderer *renderer);

    Board(int tileSize);

    const int tileSize;
};


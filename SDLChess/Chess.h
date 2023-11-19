#pragma once

#include "Board.h"

class Chess {
    Board *board;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning;

public:
    Chess(const char *title, int x, int y, int w, int h, Board *board);

    void handleEvents();
    void update();
    void clean();
    void render();

    bool running() { return isRunning; }
};
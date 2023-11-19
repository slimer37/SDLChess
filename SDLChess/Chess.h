#pragma once

class Chess {
    void renderBoard();

    int squareSize;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning;

public:
    Chess(const char *title, int x, int y, int w, int h, int squareSize);

    void handleEvents();
    void update();
    void clean();
    void render();

    bool running() { return isRunning; }
};
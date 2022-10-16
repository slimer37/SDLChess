#pragma once

class Chess {
public:
    Chess(const char *title, int x, int y, int w, int h, int squareSize);

    void handleEvents();
    void update();
    void clean();
    void render();

    bool running() { return isRunning; }
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool isRunning;
};
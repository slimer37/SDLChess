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
    SDL_Rect *square;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    bool isRunning;
};
#include <iostream>

#include "SDL.h"
#include "Chess.h"

Chess::Chess(const char *title, int x, int y, int w, int h, int squareSize) {
    if (SDL_Init(0) == 0) {
        window = SDL_CreateWindow(title, x, y, w, h, 0);

        if (!window) {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_RenderSetVSync(renderer, 1);

        if (!renderer) {
            std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Chess::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {

    case SDL_QUIT:
        isRunning = false;
        break;

    default:
        break;
    }
}

Uint64 LAST;
Uint64 NOW;
double deltaTime;

void Chess::update() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

    std::cout << 1 / deltaTime << std::endl;
}

void Chess::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned." << std::endl;
}

void Chess::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
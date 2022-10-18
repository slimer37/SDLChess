#include <iostream>

#include "SDL.h"
#include "Chess.h"

Chess::Chess(const char *title, int x, int y, int w, int h, int squareSize) {
    if (SDL_Init(0) != 0) {
        isRunning = false;
        return;
    }

    isRunning = true;

    window = SDL_CreateWindow(title, x, y, w, h, 0);

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetVSync(renderer, 1);

    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    }

    square = new SDL_Rect{ 0, 0, squareSize, squareSize };
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

void Chess::update() {
}

void Chess::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    std::cout << "Game cleaned." << std::endl;
}

const SDL_Color col1 = { 250, 225, 180 };
const SDL_Color col2 = { 120, 85, 50 };

void renderBoard(SDL_Renderer *renderer, SDL_Rect *square) {
    int &squareSize = square->w;

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            square->x = squareSize * rank;
            square->y = squareSize * file;

            const SDL_Color &col = (rank + file) % 2 == 0 ? col1 : col2;

            SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
            SDL_RenderFillRect(renderer, square);
        }
    }
}

void Chess::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    renderBoard(renderer, square);
    SDL_RenderPresent(renderer);
}
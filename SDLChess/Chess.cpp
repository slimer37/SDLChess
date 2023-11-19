#include <iostream>

#include "SDL.h"
#include "Chess.h"
#include "Position.h"
#include "Text.h"

Chess::Chess(const char *title, int x, int y, int w, int h, Board *board) {
    if (SDL_Init(0) != 0) {
        isRunning = false;
        return;
    }

    isRunning = true;

    window = SDL_CreateWindow(title, x, y, w, h, 0);

    this->board = board;

    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_RenderSetVSync(renderer, 1);

    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    }

    render();
}

Position hoverPos;

void Chess::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {

    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_MOUSEMOTION:
    {
        int &x = event.motion.x;
        int &y = event.motion.y;

        Position currPos(x, y, board->tileSize);

        if (hoverPos != currPos) {
            hoverPos = currPos;
            std::cout << hoverPos.getDisplayString() << " " << hoverPos.getIndex() << std::endl;

            board->render(renderer);
            drawText(renderer, hoverPos.getDisplayString().c_str());
            SDL_RenderPresent(renderer);
        }
    }
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

void Chess::render() {
    board->render(renderer);
    drawText(renderer, "Hello!");
    SDL_RenderPresent(renderer);
}
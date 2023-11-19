#include <iostream>

#include "SDL.h"
#include "Chess.h"
#include "Position.h"
#include "SDL_ttf.h"

void drawText(SDL_Renderer *renderer, const char *text);

TTF_Font *roboto = nullptr;

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

    if (TTF_Init() != 0) {
        std::cout << "Failed to initialize TTF: " << SDL_GetError() << std::endl;
    }

    roboto = TTF_OpenFont("Roboto.ttf", 48);

    if (roboto == nullptr) {
        std::cout << "Failed to load font: " << SDL_GetError() << std::endl;
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

void drawText(SDL_Renderer *renderer, const char *text) {
    SDL_Color color{ 0, 0, 0 };

    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(roboto, text, color);

    if (surfaceMessage == nullptr) {
        std::cout << "Error creating text surface: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    if (message == nullptr) {
        std::cout << "Error creating text texture: " << SDL_GetError() << std::endl;
        return;
    }

    int w = surfaceMessage->w / 2;
    int h = surfaceMessage->h / 2;

    SDL_Rect rect{ 320 - w / 2, 540 - h / 2, w, h };

    if (SDL_RenderCopy(renderer, message, NULL, &rect) != 0) {
        std::cout << "Error rendering text: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void Chess::render() {
    board->render(renderer);
    drawText(renderer, "Hello!");
    SDL_RenderPresent(renderer);
}
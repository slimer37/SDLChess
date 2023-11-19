#include "SDL.h"
#include "Board.h"
#include "Position.h"

const SDL_Color light = { 250, 225, 180 };
const SDL_Color dark = { 120, 85, 50 };

Board::Board(int tileSize) : tileSize(tileSize) {
    renderer = nullptr;
}

void Board::setRenderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

/// <summary>
/// Clears the buffer and renders an empty chess grid to the screen.
/// </summary>
void Board::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect square{ 0, 0, tileSize, tileSize };

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            square.x = tileSize * rank;
            square.y = tileSize * file;

            const SDL_Color &col = (rank + file) % 2 == 0 ? light : dark;

            SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
            SDL_RenderFillRect(renderer, &square);
        }
    }
}

void Board::highlight(Position position) {
    SDL_Color col = position.isLight() ? light : dark;

    col.r -= 50;
    col.g -= 50;
    col.b -= 50;

    SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);

    SDL_RenderFillRect(renderer, new SDL_Rect{ (position.fileAsInt() - 1) * tileSize, (8 - position.getRank()) * tileSize, tileSize, tileSize });
}

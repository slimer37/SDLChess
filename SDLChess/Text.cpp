#include "Text.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

TTF_Font *font;
bool ttfReady;

void initIfNeeded(const char *fontFile = "Roboto.ttf") {
    if (ttfReady) return;

    if (TTF_Init() != 0) {
        std::cout << "Failed to initialize TTF: " << SDL_GetError() << std::endl;
    }

    font = TTF_OpenFont(fontFile, 48);

    if (!fontFile) {
        std::cout << "Failed to load font: " << SDL_GetError() << std::endl;
    }

    ttfReady = true;
}

void drawText(SDL_Renderer *renderer, int x, int y, const char *text) {
    initIfNeeded();

    SDL_Color color{ 0, 0, 0 };

    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, text, color);

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

    SDL_Rect rect{ x - w / 2, y - h / 2, w, h };

    if (SDL_RenderCopy(renderer, message, NULL, &rect) != 0) {
        std::cout << "Error rendering text: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

#include "SDL.h"

#include "Chess.h"

int main(int argc, char *argv[]) {
    Chess *chess = new Chess("Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 640, 80);

    while (chess->running()) {
        chess->handleEvents();
        chess->update();
        chess->render();
    }

    chess->clean();

    return 0;
}
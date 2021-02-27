#include <Game.hpp>

int main(int argc, const char* argv[]) {
    Game game;
    game.initialize();

    unsigned int frameStart;
    int frameTime;

    while (game.running()) {
        frameStart = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - frameStart;

        if (game.frameDelay() > frameTime) {
            SDL_Delay(game.frameDelay() - frameTime);
        }
    }

    game.clean();

    return 0;
}
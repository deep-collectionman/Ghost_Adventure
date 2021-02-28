#include <iostream>

#include <ECS/ECS.hpp>
#include <ECS/Components.hpp>

#include <Game.hpp>
#include <GameConfig.hpp>
#include <Object.hpp>
#include <Map.hpp>

EntityManager manager;
auto& ghost(manager.addEntity());

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Game::Game(void) {}

Game::~Game(void) {
    clean();
}

void Game::initialize(GameConfig config) {
    this->config = config; 

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        // TODO: Replace with Logger.info("SDL Initialized");
        std::cout << "SDL Initialized" << std::endl;

        window = SDL_CreateWindow(
            config.title,
            config.rect.xpos,
            config.rect.ypos,
            config.rect.width,
            config.rect.height,
            config.isFullScreen ? SDL_WINDOW_FULLSCREEN : 0
        );

        if (window) {
            std::cout << "Window creation done" << std::endl;

            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer) {
                std::cout << "Renderer creation done" << std::endl;

                SDL_SetRenderDrawColor(
                    renderer,
                    255,
                    255,
                    255,
                    255
                );
            } else {
                throw FailedToCreateRenderer();
            }
        } else {
            throw FailedToCreateWindow();
        }
    } else {
        throw FailedToInitializeSDL();
    }

    isRunning = ((SDL_Init(SDL_INIT_EVERYTHING) == 0) && window && renderer);

    map = new Map();

    // ECS Implementation ...
    ghost.addComponent<BidimensionalPoint>(20,20);
    ghost.addComponent<Sprite>("assets/ghost.png");
}

void Game::update(void) {
    // manager.refresh();
    manager.update();

    if (ghost.getComponent<BidimensionalPoint>().x() > 40 && ghost.getComponent<BidimensionalPoint>().x() <= 200) {
        ghost.getComponent<Sprite>().setTexture("assets/hell_soldier.png");
    } else if (ghost.getComponent<BidimensionalPoint>().x() > 200) {
        ghost.getComponent<Sprite>().setTexture("assets/ghost.png");
    }
}

void Game::render(void) {
    SDL_RenderClear(Game::renderer);

    map->drawMap();
    manager.draw();

    SDL_RenderPresent(Game::renderer);
}

void Game::clean(void) {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();

    // TODO: Logger.info("Game cleaned");
}

void Game::handleEvents(void) {
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

bool Game::running(void) const {
    return isRunning;
}

int Game::frameDelay(void) const {
    return config.frameDelay;
}
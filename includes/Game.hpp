#ifndef game_hpp
#define game_hpp

#include <SDL2/SDL.h>

#include <GameConfig.hpp>

struct GameError {};

struct FailedToInitializeSDL : GameError {};
struct FailedToCreateWindow : GameError {};
struct FailedToCreateRenderer : GameError {};

static const GameConfig DEFAULT_GAME_CONFIG = {
    "Ghost Game",
    DEFAULT_SCREEN_DIMENSIONS,
    80,
    1000 / 80,
    false
};

class Game {
private:
    GameConfig config;
    bool isRunning;

    SDL_Window* window;
public:
    static SDL_Renderer* renderer;

    Game(void);
    ~Game(void);

    void initialize(GameConfig config = DEFAULT_GAME_CONFIG);
    void update();
    void render();
    void clean();

    void handleEvents(void);
    bool running(void) const;

    int frameDelay(void) const;
};

#endif /* game_hpp */

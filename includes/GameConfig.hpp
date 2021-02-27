#ifndef game_config_hpp
#define game_config_hpp

#include <Rect.hpp>

static const Rect DEFAULT_SCREEN_DIMENSIONS = {
    640,
    800,
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED
};

struct GameConfig {
    const char* title;
    Rect rect;
    int FPS;
    int frameDelay;
    bool isFullScreen;
};

#endif /* game_config_hpp */
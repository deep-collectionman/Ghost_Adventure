#ifndef texture_manager_hpp
#define texture_manager_hpp

#include <SDL2/SDL_image.h>

#include <Game.hpp>

class TextureManager {
private:
    SDL_Texture* ghostTexture;
public:
    static SDL_Texture* makeTexture(const char* filePath);
    static void draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination);
};

#endif /* *texture_manager_hpp */
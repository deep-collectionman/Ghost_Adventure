#ifndef texture_manager_hpp
#define texture_manager_hpp

#include <SDL2/SDL_image.h>

class TextureManager {
private:
    SDL_Texture* ghostTexture;
public:
    static SDL_Texture* makeTexture(const char* filePath, SDL_Renderer* renderer);
};

#endif /* *texture_manager_hpp */
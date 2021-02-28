#include <TextureManager.hpp>

SDL_Texture* TextureManager::makeTexture(const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
    SDL_FreeSurface(surface);

    return texture;
}

void TextureManager::draw(SDL_Texture* texture, SDL_Rect source, SDL_Rect destination) {
    SDL_RenderCopy(Game::renderer, texture, &source, &destination);
}
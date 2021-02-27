#include <Object.hpp>

Object::Object(
    const char* textureSheet, 
    SDL_Renderer* renderer, 
    int xPosition,
    int yPosition
) : renderer(renderer), xPosition(xPosition), yPosition(yPosition) {
    texture = TextureManager::makeTexture(textureSheet, renderer);
}

Object::~Object(void) {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
}

void Object::update(void) {
    source.h = 64;
    source.w = 64;
    source.x = 0;
    source.y = 0;

    destination.h = source.h;
    destination.w = source.w;
    destination.x = xPosition;
    destination.y = yPosition;
}

void Object::render(void) {
    SDL_RenderCopy(renderer, texture, &source, &destination);
}
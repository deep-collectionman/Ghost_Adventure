#include <Object.hpp>

Object::Object(
    const char* textureSheet,
    int xPosition,
    int yPosition
) : xPosition(xPosition), yPosition(yPosition) {
    texture = TextureManager::makeTexture(textureSheet);
}

Object::~Object(void) {
    SDL_DestroyTexture(texture);
}

void Object::update(void) {
    source.h = source.w = 64;
    source.x = source.y = 0;

    destination.h = source.h;
    destination.w = source.w;
    destination.x = xPosition;
    destination.y = yPosition;
}

void Object::render(void) {
    SDL_RenderCopy(Game::renderer, texture, &source, &destination);
}
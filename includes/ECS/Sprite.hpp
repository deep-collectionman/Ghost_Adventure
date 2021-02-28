#ifndef sprite_hpp
#define sprite_hpp

#include <SDL2/SDL.h>

#include <ECS/ECS.hpp>
#include <ECS/BidimensionalPosition.hpp>

#include <TextureManager.hpp>

class Sprite: public Component {
private:
    BidimensionalPoint* point;
    SDL_Texture* texture;
    SDL_Rect source, destination;
public:
    Sprite(void) = default;

    Sprite(const char* filePath) : Component() {
        setTexture(filePath);
    }

    virtual ~Sprite(void) override {
        point = nullptr;
        SDL_DestroyTexture(texture);
    }

    void init(void) override {
        point = &entity->getComponent<BidimensionalPoint>();

        source.x = source.y = 0;
        source.h = source.w = 32;
        destination.h = destination.w = 64;
    }

    void update(void) override {
        destination.x = point->x();
        destination.y = point->y();
    }

    void draw(void) override {
        TextureManager::draw(texture, source, destination);
    }

    void setTexture(const char* filePath) {
        texture = TextureManager::makeTexture(filePath);
    }
};

#endif /* sprite_hpp */
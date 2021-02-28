#ifndef object_hpp
#define object_hpp

#include <SDL2/SDL.h>

#include <Renderable.hpp>
#include <Updatable.hpp>

#include <TextureManager.hpp>
#include <Rect.hpp>
#include <Game.hpp>

class Object: public Renderable, public Updatable {
private:
    SDL_Texture* texture;
    SDL_Rect source, destination;

    int xPosition;
    int yPosition;
public:
    Object(const char* textureSheet, int xPosition, int yPosition);
    ~Object(void);

    virtual void update(void);
    virtual void render(void);
};

#endif /* object_hpp */
#ifndef map_hpp
#define map_hpp

#include <Game.hpp>
#include <TextureManager.hpp>

enum TILE_TYPE {
    WATER   = 0,
    GRASS   = 1,
    DIRT    = 2
};


class Map {
private:
    SDL_Rect source, destination;

    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* dirt;

    TILE_TYPE mapRepresentantion[20][25];

    void renderTile(TILE_TYPE type);
public:
    Map(void);
    ~Map(void);

    void loadMap(void);
    void drawMap(void);
};

#endif /* map_hpp */
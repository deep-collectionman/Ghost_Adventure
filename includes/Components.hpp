#ifndef components_hpp
#define components_hpp

#include <ECS.hpp>

class BidimensionalPoint: public Component {
private:
    int xPosition;
    int yPosition;
public:
    BidimensionalPoint(void) : Component() {}

    virtual ~BidimensionalPoint(void) override {
        xPosition = 0;
        yPosition = 0;
    }

    void init(void) override {
        xPosition = 0;
        yPosition = 0;
    }

    void draw(void) override {
        std::cout << "Player xpos:" << xPosition << std::endl;
        std::cout << "Player ypos:" << yPosition << std::endl;
    }

    void update(void) override {
        xPosition++;
        yPosition++;

        draw();
    }

    void set(int x, int y) {
        xPosition = x;
        yPosition = y;
    }

    int x(void) const {
        return xPosition;
    }

    int y(void) const {
        return yPosition;
    }

    void x(int x) {
        xPosition = x;
    }

    void y(int y) {
        yPosition = y;
    }
};

#endif /* components_hpp */
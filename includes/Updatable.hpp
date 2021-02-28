#ifndef updatable_hpp
#define updatable_hpp

class Updatable {
public:
    virtual ~Updatable(void) {};
    virtual void update(void) = 0; 
};

#endif /* updatable_hpp */
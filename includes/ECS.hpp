#ifndef ecs_hpp
#define ecs_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include <Updatable.hpp>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID componentTypeID(void) {
    static ComponentID lastID = 0;
    return lastID++;
}

template <typename Type>
inline ComponentID componentTypeID() noexcept {
    static ComponentID typeID = componentTypeID();
    return typeID;
}

constexpr std::size_t maxComponents = 32;

using ComponentBitSet = std::bitset<maxComponents>;
using ComponentCollection = std::array<Component*, maxComponents>;

class Component: public Updatable {
public:
    Entity* entity;

    Component(void) : entity(nullptr) {};

    virtual void init(void) = 0;
    virtual void update(void) = 0;
    virtual void draw(void) = 0;

    virtual ~Component(void) {};
};

class Entity: public Updatable {
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentCollection collection;
    ComponentBitSet bitSet;
public:
    bool isActive(void) {
        return active;
    }

    void setAsInactive(void) {
        active = false;
    }

    inline void update(void) {
        for (auto& component : components) {
            component->update();
        }
    }

    inline void draw(void) {
        for (auto& component : components) {
            component->draw();
        }
    }

    template <typename Type>
    inline bool hasComponent(void) const {
        return bitSet[componentTypeID<Type>];
    }

    template <typename Type, typename... TArgs>
    Type& addComponent(TArgs&&... anyArguments) {
        Type* component(new Type(std::forward<TArgs>(anyArguments)...));
        component->entity = this;
        std::unique_ptr<Component> pointer(component);
        components.emplace_back(std::move(pointer));

        collection[componentTypeID<Type>()] = component;
        bitSet[componentTypeID<Type>()] = true;

        component->init();
        return *component; 
    }

    template <typename Type>
    Type& getComponent(void) const {
        auto pointer(collection[componentTypeID<Type>()]);
        return *static_cast<Type*>(pointer);
    }
};

class EntityManager: public Updatable {
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    void update(void) {
        for (auto& entity : entities) {
            entity->update();
        }
    }

    void draw(void) {
        for (auto& entity : entities) {
            entity->draw();
        }
    }

    void refresh(void) {
        entities.erase(
            std::remove_if(
                std::begin(entities), 
                std::end(entities),
                [](const std::unique_ptr<Entity>& entity) {
                    return !entity->isActive();
                }
            )
        ), std::end(entities);
    }

    Entity& addEntity(void) {
        Entity* entity = new Entity();
        std::unique_ptr<Entity> pointer(entity);
        entities.emplace_back(std::move(pointer));
        return *entity;
    }
};

#endif /* ecs_hpp */
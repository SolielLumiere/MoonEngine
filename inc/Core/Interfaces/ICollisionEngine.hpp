#pragma once

#include <map>
#include <unordered_set>
#include <SFML/Graphics.hpp>

namespace MoonEngine
{
    class State;
    class GameObject;

    class ICollisionEngine
    {
        
    public:
        ICollisionEngine(State *state);
        ~ICollisionEngine();

        virtual void insert(GameObject *gameObject) = 0;
        virtual void reset() = 0;
        virtual void draw(sf::RenderWindow *win);
        virtual void erase(GameObject *e) = 0;
        virtual void handleCollisions() = 0;
    protected:
        const std::map<int, std::unordered_set<GameObject*>> &gameObjects() const;

    private:
        State* mState;
    };

}
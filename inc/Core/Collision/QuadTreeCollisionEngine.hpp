#pragma once

#include "Core/Interfaces/ICollisionEngine.hpp"
#include "Core/Collision/QuadTree.hpp"
#include <memory>

namespace MoonEngine
{
    class QuadTreeCollisionEngine : public ICollisionEngine
    {
        
    public:
        QuadTreeCollisionEngine(State *state, const sf::FloatRect &boundary, unsigned short capacity);
        ~QuadTreeCollisionEngine();


        void insert(GameObject *gameObject) override;
        void reset() override;
        void draw(sf::RenderWindow *window) override;
        void erase(GameObject *e) override;
        void handleCollisions() override;
    private:
    
        std::unique_ptr<QuadTree> mQuadTree;
        std::unordered_map<GameObject*, std::unordered_set<GameObject*>> mCollision;
    };


}



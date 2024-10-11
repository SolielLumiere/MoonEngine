#pragma once

#include "Core/GameObject/GameObject.hpp"

namespace MoonEngine
{
    class ChildGameObject : public GameObject
    {
        
    public:
        ChildGameObject(GameObject *parent, const sf::Vector2f &relativePos, float relativeAngle, int tag, const sf::Texture &texture, int layerOrder = 0);
        ~ChildGameObject();

        void update(float dt) override;

    private:
        GameObject *mParent;
        sf::Vector2f mRelative;
        float mRelativeAngle;
    };
    
}
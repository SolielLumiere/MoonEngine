#pragma once

#include "Core/Components/Component.hpp"
#include "Core/Components/Colliders/ICollider.hpp"

namespace MoonEngine
{
    class BoxCollider : public ICollider
    {

        public:
            BoxCollider(GameObject *parent, const sf::Vector2f &size, const sf::Vector2f &relativePos = sf::Vector2f(0, 0), float relativeAngle = 0, int order = -1);
            virtual ~BoxCollider();

            virtual void setPosition(const sf::Vector2f &pos) override;

            DECLARE_COMPONENT_TYPE(BoxCollider, ICollider)
    };
}
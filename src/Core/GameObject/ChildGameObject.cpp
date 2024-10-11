#include "Core/GameObject/ChildGameObject.hpp"
#include "Core/Math/Math.hpp"


MoonEngine::ChildGameObject::ChildGameObject(GameObject *parent, const sf::Vector2f &relativePos, float relativeAngle, int tag, const sf::Texture &texture, int layerOrder)
    :   GameObject(tag, texture, layerOrder),
        mParent(parent),
        mRelative(relativePos),
        mRelativeAngle(relativeAngle)
{
    setPosition(mParent->getPosition() + mRelative);
    setRotation(mParent->getRotation() + mRelativeAngle);
}

MoonEngine::ChildGameObject::~ChildGameObject()
{
}

void MoonEngine::ChildGameObject::update(float dt)
{
    if (mParent != nullptr) {
        setRotation(mParent->getRotation() + mRelativeAngle);
    
        float angle = Math::degreesToRadians(getRotation());
        sf::Vector2f rotatedRelativePosition(
            mRelative.x * std::cos(angle) - mRelative.y * std::sin(angle),
            mRelative.x * std::sin(angle) + mRelative.y * std::cos(angle)
        );
      
        setPosition(mParent->getPosition() + rotatedRelativePosition);
    }
    GameObject::update(dt);
}

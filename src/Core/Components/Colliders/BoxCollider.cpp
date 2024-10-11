#include "Core/Components/Colliders/BoxCollider.hpp"
#include "Core/GameObject/GameObject.hpp"

using namespace MoonEngine;



BoxCollider::BoxCollider(GameObject *parent, const sf::Vector2f &size, const sf::Vector2f &relativePos, float relativeAngle, int order)
    :   ICollider(parent, relativePos, relativeAngle, order)
{
    mColliders.push_back(new sf::RectangleShape(size));
    mColliders.front()->setPosition(parent->getPosition());

    sf::Vector2f textureSize = getCollider<sf::RectangleShape>(0)->getSize();
    mColliders.front()->setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);       
    mColliders.front()->setFillColor(sf::Color::Transparent);
    mColliders.front()->setOutlineColor(sf::Color::Green);
    mColliders.front()->setOutlineThickness(2); 

}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::setPosition(const sf::Vector2f &pos)
{
    mColliders.front()->setPosition(pos);
}
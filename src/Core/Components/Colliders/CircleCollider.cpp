#include "Core/Components/Colliders/CircleCollider.hpp"



MoonEngine::CircleCollider::CircleCollider(GameObject *parent, float radius, int order)
    :   ICollider(parent, sf::Vector2f(0, 0), 0, order)
{
    mColliders.push_back(new sf::CircleShape(radius));
    mColliders.front()->setPosition(parent->getPosition());
    mColliders.front()->setOrigin(radius, radius);       
    mColliders.front()->setFillColor(sf::Color::Transparent);
    mColliders.front()->setOutlineColor(sf::Color::Green);
    mColliders.front()->setOutlineThickness(2); 


}

MoonEngine::CircleCollider::~CircleCollider()
{
}
void MoonEngine::CircleCollider::update(float dt)
{
    mColliders.front()->setPosition(parent()->getPosition());
    mColliders.front()->setRotation(parent()->getRotation());
}
#include "Core/Components/Colliders/ICollider.hpp"
#include "Core/GameObject/GameObject.hpp"
#include "Core/Math/Math.hpp"

using namespace MoonEngine;

ICollider::ICollider(GameObject *parent, const sf::Vector2f &relativePos, float relativeAngle, int order)
    :   Component(parent, order),
        mIsTrigger(true),
        mRelative(relativePos),
        mRelativeAngle(relativeAngle)
{

}

ICollider::~ICollider()
{
}

bool MoonEngine::ICollider::intersects(const ICollider *other)
{
    const std::vector<sf::Shape*> &otherColliders = other->colliders();
    
    for(const sf::Shape *thisCollider : mColliders)
    {
        for(const sf::Shape *otherCollider : otherColliders)
        {
            if(thisCollider->getGlobalBounds().intersects(otherCollider->getGlobalBounds()))
            {
                return true;
            }
        }
    }

    return false;
}

bool MoonEngine::ICollider::intersects(const sf::FloatRect &other)
{
    
    for(const sf::Shape *thisCollider : mColliders)
    {
        if(thisCollider->getGlobalBounds().intersects(other))
        {
            return true;
        }
    }

    return false;
    
}
void MoonEngine::ICollider::update(float dt)
{
    Component::update(dt);
    if (parent() != nullptr)
    {
        for (sf::Shape *thisCollider : mColliders)
        {

           thisCollider->setRotation(parent()->getRotation() + mRelativeAngle);
            float angle = Math::degreesToRadians(thisCollider->getRotation());
            sf::Vector2f rotatedRelativePosition(
                mRelative.x * std::cos(angle) - mRelative.y * std::sin(angle),
                mRelative.x * std::sin(angle) + mRelative.y * std::cos(angle));

            thisCollider->setPosition(parent()->getPosition() + rotatedRelativePosition); 
        }
    }

}

const std::vector<sf::Shape*> &ICollider::colliders() const
{
    return mColliders;
}


void ICollider::draw(sf::RenderWindow *window)
{
    
    #ifdef SHOW_COLLIDERS

        if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            for(const sf::Shape* rec : mColliders)
            {
                window->draw(*rec);
            }
        }

    #endif
}

void MoonEngine::ICollider::setPosition(const sf::Vector2f &pos)
{
    
}

sf::Vector2f MoonEngine::ICollider::getCenter() const
{
    const sf::FloatRect boundary = mColliders.front()->getGlobalBounds();
    return sf::Vector2f{
        boundary.left + (boundary.width/2.f),
        boundary.top + (boundary.height/2.f)
    };
}

void MoonEngine::ICollider::setColor(const sf::Color &color)
{
    for(sf::Shape* collider : mColliders)
    {
        collider->setOutlineColor(color);
    }
}

void MoonEngine::ICollider::setFillColor(const sf::Color &color)
{
    for(sf::Shape* collider : mColliders)
    {
        collider->setFillColor(color);
    }
}
void MoonEngine::ICollider::setOrigin(const sf::Vector2f &origin)
{
    for(sf::Shape* collider : mColliders)
    {
        collider->setOrigin(origin);
    }
}

bool ICollider::isTrigger()
{
    return mIsTrigger;
}

void ICollider::setIsTrigger(bool isTrigger)
{
    mIsTrigger = isTrigger;
}

bool ICollider::operator == (const sf::FloatRect &rect)
{
    for(sf::Shape* collider : mColliders)
    {
        if(collider->getGlobalBounds() == rect)
        {
            return true;
        }
    }
    return false;
}

bool ICollider::operator == (const ICollider &other)
{
    for(const sf::Shape* collider : mColliders)
    {
       for(const sf::Shape* collider2 : other.mColliders)
       {
            if(collider->getGlobalBounds() == collider2->getGlobalBounds() && collider->getPosition() == collider2->getPosition())
            {
                return true;
            }
       }
    }

    return false;
}

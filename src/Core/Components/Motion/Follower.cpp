#include "Core/Components/Motion/Follower.hpp"
#include "Core/Math/Math.hpp"
using namespace MoonEngine;

Follower::Follower( GameObject *parent, 
                    GameObject *target, 
                    float speed, 
                    float offsetAngle, 
                    float offsetDistance, 
                    float rotationAngle,
                    int order )
    :   Component(parent, order),
        mTarget(target),
        mSpeed(speed),
        mOffsetAngle(offsetAngle),
        mOffsetDistance(offsetDistance),
        mRotationAngle(rotationAngle)

{   

}

void Follower::update(float dt)
{

    sf::Vector2f tagetPosition = mTarget->getPosition();

    sf::Vector2f offset(cos(MoonEngine::Math::degreesToRadians(mOffsetAngle)) * mOffsetDistance, sin(MoonEngine::Math::degreesToRadians(mOffsetAngle)) * mOffsetDistance);
    sf::Vector2f targetPosition = tagetPosition + offset;

    sf::Vector2f currentPosition = parent()->getPosition();
    sf::Vector2f direction = targetPosition - currentPosition;
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction.x /= length;
        direction.y /= length;
    }

    sf::Vector2f newPosition = currentPosition + direction * mSpeed * dt;
    sf::Vector2f unit = MoonEngine::Math::normalize(tagetPosition - currentPosition);

    parent()->setRotation(MoonEngine::Math::unitVectorToAngle(unit) + mRotationAngle);
    parent()->move(direction * mSpeed * dt);

}

Follower::~Follower()
{

}
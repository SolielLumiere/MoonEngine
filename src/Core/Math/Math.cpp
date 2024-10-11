#include "Core/Math/Math.hpp"

using namespace MoonEngine;

sf::Vector2f Math::normalize(const sf::Vector2f &vec)
{
    float length = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    if(length == 0)
    {
        return sf::Vector2f(0, 0);
    }

    return sf::Vector2f(vec.x / length, vec.y / length);
}

float Math::distance(const sf::Vector2f &source, const sf::Vector2f &destiny)
{
    sf::Vector2f direction = destiny - source;
    return std::sqrt(direction.x * direction.x + direction.y * direction.y);
}

sf::Vector2f Math::angleToUnitVector(double angleInDegress) 
{
    double angleinRadians = degreesToRadians(angleInDegress);
    
    double x = cos(angleinRadians);
    double y = sin(angleinRadians);
    return sf::Vector2f(x, y);
}

float MoonEngine::Math::unitVectorToAngle(const sf::Vector2f &unit)
{
    float angleRadians = std::atan2(unit.y, unit.x);
    return angleRadians * 180.0f / M_PI;
}

double MoonEngine::Math::degreesToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}

double MoonEngine::Math::radiansToDegress(double radians)
{
    return radians * 180.0f / M_PI;
}
float MoonEngine::Math::lerp(float goal, float current, float dt)
{
    float flDifference = goal - current;

    if (flDifference > dt)
        return current + dt;
    if (flDifference < -dt)
        return current - dt;

    return goal;
}
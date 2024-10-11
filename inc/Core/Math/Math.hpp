#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace MoonEngine 
{
    class Math
    {
        private:
            ~Math() = delete;
            Math() = delete;
            
        public:
            static sf::Vector2f normalize(const sf::Vector2f& vec);
            static float distance(const sf::Vector2f& source, const sf::Vector2f& destiny);
            static sf::Vector2f angleToUnitVector(double angleInDegress);
            static float unitVectorToAngle(const sf::Vector2f &unit);    
            static double degreesToRadians(double degrees);
            static double radiansToDegress(double radians);
            static float lerp(float goal, float current, float dt);

    };
}


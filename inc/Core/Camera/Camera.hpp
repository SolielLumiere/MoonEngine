#pragma once

#include <SFML/Graphics.hpp>
#include "Core/Behavior/Behavior.hpp"

namespace MoonEngine
{
    class Camera : public Behavior
    {
    public:
        Camera(sf::RenderWindow *window);
        virtual ~Camera();
        
        void move(const sf::Vector2f &position);
        void setSize(const sf::Vector2f &newSize);
        const sf::View &view() const;

    protected:
        sf::RenderWindow *mWindow;
        sf::View mView;
    };
}
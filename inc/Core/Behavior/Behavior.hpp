#pragma once 

#include <SFML/Graphics.hpp>
#include <vector>


namespace MoonEngine 
{   
    class Behavior
    {
        
    public:
        virtual ~Behavior();
        virtual void start();
        virtual void handleInputs(const sf::Event &event);
        virtual void update(float dt);
        virtual void draw(sf::RenderWindow *window);
        virtual void onResize(sf::RenderWindow *window);
        virtual void onCreate(sf::RenderWindow *window);

    protected:
        Behavior();
    };
}


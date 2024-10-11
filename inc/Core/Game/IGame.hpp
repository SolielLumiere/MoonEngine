#pragma once

#include <SFML/Graphics.hpp>


namespace MoonEngine
{

    class IGame : public sf::RenderWindow
    {
        
    public:
        ~IGame();
        
    protected:
        IGame(unsigned int width, unsigned int heigh, const std::string &title);
        virtual void handleEvents() = 0;
        virtual void start() = 0;
        virtual void update() = 0;
        virtual void render() = 0;


    };
}



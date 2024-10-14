#include "Core/Game/Game.hpp"
#include "Core/Components/StateHandler.hpp"

using namespace MoonEngine;

Game::Game(unsigned int width, unsigned int height, const std::string &title)
    :   IGame(width, height, title)
{


}

Game::~Game()
{
    
}

void MoonEngine::Game::onCreate()
{
    StateHandler::instance()->onCreate(this);
}


void Game::start()
{
    StateHandler::instance()->start();

    while (isOpen())
    {
        handleEvents();
        update();
        render();
    }
    
}

void MoonEngine::Game::setBackgroundColor(sf::Color color)
{
    mColor = color;
}

void MoonEngine::Game::handleEvents()
{
    sf::Event event;
    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            close();
        }      
        StateHandler::instance()->handleInputs(event);
    }
}


void Game::update()
{
    StateHandler::instance()->update(deltaTime());
}


void Game::render()
{
    clear(mColor);
    
    StateHandler::instance()->draw(this);

    display();


}

void Game::onResize()
{   
    StateHandler::instance()->onResize(this);
    sf::Vector2u newSize = getSize();
    sf::FloatRect rec(0, 0, newSize.x, newSize.y);
    
    setView(sf::View(rec));
}


float Game::deltaTime()
{
    return mClock.restart().asSeconds();
}


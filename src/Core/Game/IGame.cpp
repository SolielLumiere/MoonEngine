#include "Core/Game/IGame.hpp"
#include "Core/Components/MousePosition.hpp"
#include "Core/Components/StateHandler.hpp"

using namespace MoonEngine;

IGame::IGame(unsigned int width, unsigned int height, const std::string &title)
    :   sf::RenderWindow(sf::VideoMode(width, height), title)
{
    MousePosition::init(this);
    StateHandler::init();
}

IGame::~IGame()
{

}


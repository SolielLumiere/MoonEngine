#include "Core/Components/MousePosition.hpp"


using namespace MoonEngine;

std::unique_ptr<MousePosition> MousePosition::mInstance;


MousePosition::MousePosition(IGame *game)
    :   mIGame(game)
{

}


MousePosition::~MousePosition()
{

}

void MousePosition::init(IGame *game)
{
    mInstance.reset(new MousePosition(game));
}


sf::Vector2i MousePosition::position() const
{
    sf::Vector2i mousePositionWindow = sf::Mouse::getPosition(*mIGame);
    sf::Vector2f mousePositionView = mIGame->mapPixelToCoords(mousePositionWindow); 
    return static_cast<sf::Vector2i>(mousePositionView);
}


MousePosition* MousePosition::instance()
{
    if(mInstance == nullptr)
    {
        printf("ERROR MousePosition NOT INITIALIZED");
        exit(-1);
    }

    return mInstance.get();
}

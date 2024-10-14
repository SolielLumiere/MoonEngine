#include "Cards/Components/CardMouseListener.h"
#include "Core/Components/MousePosition.hpp"

CardMouseListener::CardMouseListener(MoonEngine::GameObject *parent)
    :   MouseListener(parent),
        mIsButtonPressed(false)
{
}

CardMouseListener::~CardMouseListener()
{

}

void CardMouseListener::update(float dt)
{
    MouseListener::update(dt);

    if(mIsButtonPressed)
    {
        sf::Vector2i pos = MoonEngine::MousePosition::instance()->position();

        parent()->setPosition((sf::Vector2f)pos);
    }
}

void CardMouseListener::onMouseEnter()
{

}

void CardMouseListener::onMouseExit()
{

}

void CardMouseListener::onLeftButtonPressed()
{
    mIsButtonPressed = true;
}

void CardMouseListener::onLeftButtonReleased()
{
    mIsButtonPressed = false;
}

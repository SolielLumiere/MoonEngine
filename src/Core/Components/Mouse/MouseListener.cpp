#include "Core/Components/Mouse/MouseListener.hpp"
#include "Core/GameObject/GameObject.hpp"
#include "Core/Components/MousePosition.hpp"


MoonEngine::MouseListener::MouseListener(GameObject *parent, int order)
    :   Component(parent, order),  
        mMouseEnter(false),
        mButtonPressed(false)
{
    mCollider = parent->getComponent<ICollider>();

}

MoonEngine::MouseListener::~MouseListener()
{
}

void MoonEngine::MouseListener::update(float dt)
{
    if(mCollider == nullptr)
    {
        return;
    }
    
    sf::FloatRect mouseRect((sf::Vector2f)MousePosition::instance()->position(), sf::Vector2f(1, 1));

    if(mCollider->intersects(mouseRect) && !mMouseEnter)
    {
        mMouseEnter = true;
        printf("Mouse Inside!!\n\r");
    }

    if(mMouseEnter && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !mButtonPressed)
    {
        printf("Button Pressed\n\r");
        mButtonPressed = true;
    }

     if(mMouseEnter && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && mButtonPressed)
    {
        printf("Button Released\n\r");
        mButtonPressed = false;
    }

  
    if(mMouseEnter && !mCollider->intersects(mouseRect))
    {
        mMouseEnter = false;
        mButtonPressed = false;
        printf("Mouse Out!!\n\r");
    }

}

#include "Core/Components/Mouse/MouseListener.hpp"
#include "Core/Components/MousePosition.hpp"


MoonEngine::MouseListener::MouseListener(GameObject *parent, int order)
    :   Component(parent, order),  
        mMouseEnter(false)

{
    mCollider = parent->getComponent<ICollider>();

}

MoonEngine::MouseListener::~MouseListener()
{
}

void MoonEngine::MouseListener::update(float dt)
{
    Component::update(dt);
    if(mCollider == nullptr)
    {
        return;
    }
    
    sf::FloatRect mouseRect((sf::Vector2f)MousePosition::instance()->position(), sf::Vector2f(1, 1));

    if(mCollider->intersects(mouseRect) && !mMouseEnter)
    {
        mMouseEnter = true;
        onMouseEnter();
    }
  
    if(mMouseEnter && !mCollider->intersects(mouseRect))
    {
        mMouseEnter = false;
        onMouseExit();
    }


}

void MoonEngine::MouseListener::handleInputs(const sf::Event &event)
{
    Component::handleInputs(event);

    sf::FloatRect mouseRect((sf::Vector2f)MousePosition::instance()->position(), sf::Vector2f(1, 1));

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && mCollider->intersects(mouseRect))
    {
        
        onLeftButtonPressed();
    }

    if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && mCollider->intersects(mouseRect))
    {
        onLeftButtonReleased();
    }
}

void MoonEngine::MouseListener::onMouseEnter()
{
    printf("Mouse Enter \n\r");
}

void MoonEngine::MouseListener::onMouseExit()
{
    printf("Mouse Exit \n\r");
}

void MoonEngine::MouseListener::onLeftButtonPressed()
{
    printf("Left Buttton Pressed \n\r");
}

void MoonEngine::MouseListener::onLeftButtonReleased()
{
    printf("Left Buttton Released \n\r");
}

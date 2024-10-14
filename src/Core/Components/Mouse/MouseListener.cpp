#include "Core/Components/Mouse/MouseListener.hpp"
#include "Core/GameObject/GameObject.hpp"
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
  
    if(mMouseEnter && !mCollider->intersects(mouseRect))
    {
        mMouseEnter = false;
        printf("Mouse Out!!\n\r");
    }


}

void MoonEngine::MouseListener::handleInputs(const sf::Event &event)
{
    Component::handleInputs(event);

    sf::FloatRect mouseRect((sf::Vector2f)MousePosition::instance()->position(), sf::Vector2f(1, 1));

    if(event.type == sf::Event::MouseButtonPressed && mCollider->intersects(mouseRect))
    {
        printf("Click Inside!!\n\r");

    }

    if(event.type == sf::Event::MouseButtonReleased && mCollider->intersects(mouseRect))
    {
        printf("Click released!!\n\r");

    }
}

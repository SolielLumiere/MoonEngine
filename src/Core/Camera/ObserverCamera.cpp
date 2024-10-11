#include "ObserverCamera.hpp"
#include "Core/GameObject/GameObject.hpp"

using namespace MoonEngine;

ObserverCamera::ObserverCamera(GameObject *subject, sf::RenderWindow *window)
    :   Camera(window),
        mSubject(subject)
{


}

MoonEngine::ObserverCamera::~ObserverCamera()
{

}


void MoonEngine::ObserverCamera::handleInputs(const sf::Event &event)
{
    if(event.type == sf::Event::Resized)
    {
        setSize(sf::Vector2f(event.size.width, event.size.height));
    }
}

void MoonEngine::ObserverCamera::update(float dt)
{
    move(mSubject->getPosition());
}

void MoonEngine::ObserverCamera::draw(sf::RenderWindow *window)
{
}
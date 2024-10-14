#include "Core/Camera/Camera.hpp"



using namespace MoonEngine;

Camera::Camera(sf::RenderWindow *window) 
    : mWindow(window) 
{
}

Camera::~Camera()
{
}


void Camera::move(const sf::Vector2f &position) 
{
    
    mView.setCenter(position);
    mWindow->setView(mView);
}

void MoonEngine::Camera::setSize(const sf::Vector2f &newSize)
{
    mView.setSize(newSize);
}

const sf::View &MoonEngine::Camera::view() const
{
    return mView;
}
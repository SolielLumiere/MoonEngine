#include "Core/Components/StateHandler.hpp"


using namespace MoonEngine;

StateHandler *StateHandler::mInstance = nullptr;

StateHandler::StateHandler()
    :   mCurrentState(nullptr)
{
}

StateHandler::~StateHandler()
{
}

void StateHandler::init()
{
    mInstance = new StateHandler();
}

StateHandler *MoonEngine::StateHandler::instance()
{
    return mInstance;
}
void StateHandler::start()
{
    if (mCurrentState == nullptr)
        return;
    mCurrentState->start();
}

void StateHandler::handleInputs(const sf::Event &event)
{
    if (mCurrentState == nullptr)
        return;

    mCurrentState->handleInputs(event);
}

void StateHandler::update(float dt)
{
    if (mCurrentState == nullptr)
        return;

    mCurrentState->update(dt);
}

void StateHandler::draw(sf::RenderWindow *window)
{
    if (mCurrentState == nullptr)
        return;
    mCurrentState->draw(window);
}

void MoonEngine::StateHandler::onResize(sf::RenderWindow *window)
{
    if (mCurrentState == nullptr)
        return;
    mCurrentState->onResize(window);
}

void StateHandler::setState(State *newState)
{
    mCurrentState = newState;
}

void StateHandler::instanciate(GameObject *e)
{
    if (mCurrentState == nullptr)
        return;

    mCurrentState->addGameObject(e);
    e->start();
}

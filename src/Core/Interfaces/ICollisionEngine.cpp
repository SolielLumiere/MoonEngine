#include "Core/Interfaces/ICollisionEngine.hpp"
#include "Core/States/State.hpp"

using namespace MoonEngine;

ICollisionEngine::ICollisionEngine(State *state)
    :   mState(state)
{
}

ICollisionEngine::~ICollisionEngine()
{
}
void MoonEngine::ICollisionEngine::draw(sf::RenderWindow *win)
{
}

const std::map<int, std::unordered_set<GameObject *>> &ICollisionEngine::gameObjects() const
{
    return mState->mGameObjects;
}
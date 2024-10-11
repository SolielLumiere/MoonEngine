#include "Core/States/State.hpp"
#include <queue>

using namespace MoonEngine;

State::State(ICollisionEngine *engine)
{
    mCollisionEngine.reset(engine);
}


State::~State()
{
    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            delete e;
        }
    }
}


void State::onCreate(sf::RenderWindow *window)
{
    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->onCreate(window);
        }
    }
}

void MoonEngine::State::start()
{
    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->start();
        }
    }
}

void State::handleInputs(const sf::Event &event)
{
    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->handleInputs(event);
        }
    }

}


void State::update(float dt)
{
    std::queue<GameObject*> q;

    if(mCollisionEngine != nullptr)
    {
        mCollisionEngine->reset();
    }

    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->update(dt);
            if(e->isDestroyed())
            {
                q.push(e);
            }
            else if(mCollisionEngine != nullptr) 
            {
                mCollisionEngine->insert(e);
            }
        }
    }

    handleErase(q);
    if(mCollisionEngine != nullptr)
    {
        mCollisionEngine->handleCollisions();
    }

}

void State::draw(sf::RenderWindow *window)
{
    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->draw(window);
        }
    }
}

void MoonEngine::State::onResize(sf::RenderWindow *window)
{

    for(auto &it : mGameObjects)
    {
        for(GameObject *e : it.second)
        {
            e->onResize(window);
        }
    }
}


void State::addGameObject(GameObject *e)
{
    mGameObjects[e->layerOrder()].insert(e);
}

void State::onEntityRequestDelete(GameObject *e)
{
    mGameObjects[e->layerOrder()].erase(e);
    if(mCollisionEngine != nullptr)
    {
        mCollisionEngine->erase(e);
    }
}

void MoonEngine::State::handleErase(std::queue<GameObject *> &q)
{
    while(!q.empty())
    {
        GameObject *go = q.front();
        q.pop();

        go->onDestroy();
        onEntityRequestDelete(go);
    }
}
#include "Core/Behavior/MonoBehavior.hpp"

using namespace MoonEngine;

MonoBehavior::MonoBehavior(int tag)
    :   mTag(tag),
        mRequestDestroy(false)
{

}


MonoBehavior::~MonoBehavior()
{

}

void MonoBehavior::start() 
{
    std::map<int, std::list<Component *>> order = getOrder();

    for(auto &[key, components] : order)
    {
        for(Component *c : components)
        {
            c->start();
        }
    }

    mRequestDestroy = false;
}

void MonoBehavior::handleInputs(const sf::Event &event)
{

    std::map<int, std::list<Component *>> order = getOrder();

    for(auto &[key, components] : order)
    {
        for(Component *c : components)
        {
            c->handleInputs(event);
        }
    }
}

void MonoBehavior::update(float dt)
{
    std::map<int, std::list<Component *>> order = getOrder();

    for(auto &[key, components] : order)
    {
        for(Component *c : components)
        {
            c->update(dt);
        }
    }
}

void MonoBehavior::draw(sf::RenderWindow *window)
{
    std::map<int, std::list<Component *>> order = getOrder();

    for(auto &[key, components] : order)
    {
        for(Component *c : components)
        {
            c->draw(window);
        }
    }
}

int MonoBehavior::tag() const
{
    return mTag;
}

void MonoBehavior::setRequestDestoy(bool request)
{
    mRequestDestroy = request;
}

bool MonoBehavior::isDestroyed() const
{
    return mRequestDestroy;
}
void MoonEngine::MonoBehavior::setTag(int tag)
{
    mTag = tag;
}

std::map<int, std::list<Component *>> MoonEngine::MonoBehavior::getOrder() const
{
    std::map<int, std::list<Component *>> order;

    for(const auto &pair : mComponents)
    {
        order[pair.second->order()].push_back(pair.second.get());
    }

    return order;
}
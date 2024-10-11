#include "Core/GameObject/GameObject.hpp"
#include "Core/Components/StateHandler.hpp"



using namespace MoonEngine;

GameObject::GameObject(int tag, const sf::Texture &texture, int layerOrder)
    :   MonoBehavior(tag),
        mLayerOrder(layerOrder)
{
    setTexture(texture);    
    add(0, this);
}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow *win)
{
    for(auto &[order, go] : mHierachy)
    {
        if(go == this) 
        {
            win->draw(*this);
        }
        else 
        {
            go->draw(win);
        }
    }
    MonoBehavior::draw(win);
}

void MoonEngine::GameObject::update(float dt)
{
    MonoBehavior::update(dt);
    for(auto &[order, go] : mHierachy)
    {
        if(go == this)
        {
            continue;
        }

        go->update(dt);
    }
}

void MoonEngine::GameObject::setCenterOrigin()
{
    sf::Vector2i textureSize = getTextureRect().getSize();
    setOrigin(textureSize.x / 2.f, textureSize.y / 2.f);        
}

void GameObject::onTriggerEnter(GameObject *other)
{
    
}

void MoonEngine::GameObject::onTriggerExit(GameObject *other)
{
}
void MoonEngine::GameObject::instanciate(GameObject *e)
{
    StateHandler::instance()->instanciate(e);
}

int MoonEngine::GameObject::layerOrder() const
{
    return mLayerOrder;
}

void MoonEngine::GameObject::add(int order, GameObject *e)
{
    mHierachy[order] = e;
}

void GameObject::onDestroy()
{

}


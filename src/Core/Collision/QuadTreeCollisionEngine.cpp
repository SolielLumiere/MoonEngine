
#include "QuadTreeCollisionEngine.hpp"
#include "Core/States/State.hpp"


using namespace MoonEngine;

QuadTreeCollisionEngine::QuadTreeCollisionEngine(State *state, const sf::FloatRect &boundary, unsigned short capacity)
    :   ICollisionEngine(state)
{
    mQuadTree.reset(new QuadTree(boundary, capacity));
}
MoonEngine::QuadTreeCollisionEngine::~QuadTreeCollisionEngine()
{

}
void MoonEngine::QuadTreeCollisionEngine::insert(GameObject *gameObject)
{
    if(gameObject->getComponent<ICollider>() != nullptr)
    {
        mQuadTree->insert(gameObject);
    }
}

void MoonEngine::QuadTreeCollisionEngine::reset()
{
    mQuadTree->reset();
}
void MoonEngine::QuadTreeCollisionEngine::draw(sf::RenderWindow *window)
{
    mQuadTree->draw(window);
}
void MoonEngine::QuadTreeCollisionEngine::erase(GameObject *e)
{
    mCollision.erase(e);
}
void MoonEngine::QuadTreeCollisionEngine::handleCollisions()
{
    for(auto &it1 : gameObjects())
    {
        for(GameObject *go : it1.second)
        {

            MoonEngine::ICollider *src = go->getComponent<MoonEngine::ICollider>();
            if(src == nullptr || !src->isTrigger() || go->isDestroyed())
            {
                continue;
            }

            std::vector<GameObject *> objectsInCell = mQuadTree->query(src);
            for(GameObject *go2 : objectsInCell)
            {
                MoonEngine::ICollider *dst = go2->getComponent<MoonEngine::ICollider>();
                if(dst == nullptr || go2->isDestroyed() || go == go2 || mCollision[go].count(go2) == 1)
                {
                    continue;
                }

                bool intersecs = src->intersects(dst);
                if(intersecs && mCollision[go].count(go2) == 0)
                {
                    go->onTriggerEnter(go2);
                    mCollision[go].insert(go2);
                }
            }
        }
    }

    std::queue<std::pair<GameObject*, GameObject*>> q;

    for(auto [go, gameObjects] : mCollision)
    {

        ICollider *colliderA = go->getComponent<ICollider>();

        for(GameObject *go2 : gameObjects)
        {
            if(go->isDestroyed() || go2->isDestroyed())
            {
                q.push(std::make_pair(go, go2));
                q.push(std::make_pair(go2, go));
                continue;
            }

            ICollider *colliderB = go2->getComponent<ICollider>();

            if(!colliderA->intersects(colliderB))
            {
                go->onTriggerExit(go2);
                q.push(std::make_pair(go, go2));
            }
        }
    }

    while (!q.empty())
    {
        std::pair<GameObject*, GameObject*> pair = q.front();
        q.pop();
        

        mCollision[pair.first].erase(pair.second);
    }

}
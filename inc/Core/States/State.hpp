#pragma once

#include "Core/GameObject/GameObject.hpp"
#include "Core/Interfaces/ICollisionEngine.hpp"

#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <memory>

namespace MoonEngine 
{
    class ICollisionEngine;

    class State : public Behavior
    {
        friend class ICollisionEngine;
        
    public:
        virtual ~State();
        virtual void handleInputs(const sf::Event &event) override;
        virtual void start() override;
        virtual void update(float dt) override;
        virtual void draw(sf::RenderWindow *window) override;
        virtual void onResize(sf::RenderWindow *window) override;
        virtual void addGameObject(GameObject* e);
        virtual void onCreate(sf::RenderWindow *window);
    protected:
        State(ICollisionEngine *mEngine = nullptr);
        virtual void onEntityRequestDelete(GameObject *e);
        std::map<int, std::unordered_set<GameObject*>> mGameObjects;
        std::unique_ptr<ICollisionEngine> mCollisionEngine;
    private:
        void handleErase(std::queue<GameObject*> &q);
    };
}


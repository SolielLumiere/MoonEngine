#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "Core/Behavior/MonoBehavior.hpp"
#include "Core/Components/Colliders/BoxCollider.hpp"

namespace MoonEngine
{
    class GameObject : public sf::Sprite, public MonoBehavior
    {
        
    public:
        GameObject(int tag, const sf::Texture &texture, int layerOrder = 0);
        virtual ~GameObject();

        virtual void draw(sf::RenderWindow *win) override;
        virtual void update(float dt) override;

        virtual void onTriggerEnter(GameObject *other);
        virtual void onTriggerExit(GameObject *other);
        virtual void onDestroy();

        void instanciate(GameObject *e);
        int layerOrder() const;
    protected:
        void add(int order, GameObject *e);
        void setCenterOrigin();
        int mLayerOrder;
        std::map<int, GameObject*> mHierachy;
    };
}


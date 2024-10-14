#pragma once

#include "Core/Components/Component.hpp"
#include "Core/Components/Colliders/ICollider.hpp"


namespace MoonEngine
{
    class MouseListener : public Component
    {
        
    public:
        MouseListener(GameObject *parent, int order = -1);
        ~MouseListener();

        void update(float dt) override;
        void handleInputs(const sf::Event &event) override;
        DECLARE_COMPONENT_TYPE(MouseListener, Component)

    protected:
        ICollider *mCollider;
        bool mMouseEnter;

        virtual void onMouseEnter();
        virtual void onMouseExit();
        virtual void onLeftButtonPressed();
        virtual void onLeftButtonReleased();
    };

}


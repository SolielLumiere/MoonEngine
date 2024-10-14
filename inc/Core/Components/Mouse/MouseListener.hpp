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
    private:
        ICollider *mCollider;
        bool mMouseEnter;
        bool mButtonPressed;
        
    };

}


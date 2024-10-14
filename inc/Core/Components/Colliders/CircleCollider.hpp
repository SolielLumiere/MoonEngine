#pragma once

#include "Core/Components/Colliders/ICollider.hpp"
#include "Core/GameObject/GameObject.hpp"

namespace MoonEngine
{
    class CircleCollider: public ICollider
    {
        
    public:
        CircleCollider(GameObject *parent, float radius ,int order = -1);
        ~CircleCollider();
        void update(float dt) override;

        DECLARE_COMPONENT_TYPE(CircleCollider, ICollider)
    protected:
        
    };
    
}
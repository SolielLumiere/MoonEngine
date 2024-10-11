#pragma once

#include "Core/GameObject/GameObject.hpp"
#include "Core/Components/Component.hpp"

namespace MoonEngine 
{
    class Follower : public Component
    {
        
    public:
        Follower(   GameObject *parent, 
                    GameObject *target, 
                    float speed, 
                    float offsetAngle, 
                    float offsetDistance, 
                    float rotationAngle,
                    int order);
        void update(float dt) override;
        virtual ~Follower();
    private:

        GameObject *mTarget;
        float mSpeed;
        float mOffsetAngle;
        float mOffsetDistance;
        float mRotationAngle;
    };



}


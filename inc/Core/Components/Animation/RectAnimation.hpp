#pragma once

#include <vector>
#include "Core/Components/Component.hpp"
#include "Core/GameObject/GameObject.hpp"


namespace MoonEngine
{
    class RectAnimation : public Component
    {
        
    public:
        RectAnimation(GameObject *parent, float durationInMillis, const std::vector<sf::IntRect> &rectFrams = {});
        virtual ~RectAnimation();

        void addRect(const sf::IntRect &frameRect);
        void update(float dt) override;
        void setRect(int index);
        void setLastRect();
        virtual void onAnimationComplete();
    
    protected:
        float mDurationInSeconds;
        std::vector<sf::IntRect> mRectFrames;
        float mCurrentTime;
        int mCurrentIndex;
    };

}


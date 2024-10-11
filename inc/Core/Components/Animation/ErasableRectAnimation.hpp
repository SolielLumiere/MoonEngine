#pragma once 

#include "Core/Components/Animation/RectAnimation.hpp"

namespace MoonEngine 
{
    class ErasableRectAnimation : public RectAnimation
    {
        
    public:
        ErasableRectAnimation(GameObject *parent, float durationInMillis, const std::vector<sf::IntRect> &rectFrams = {});
        ~ErasableRectAnimation();
        void onAnimationComplete() override;
    };

}


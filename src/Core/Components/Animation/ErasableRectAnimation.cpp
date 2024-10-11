#include "Core/Components/Animation/ErasableRectAnimation.hpp"



using namespace MoonEngine;

ErasableRectAnimation::ErasableRectAnimation(GameObject *parent, float durationInMillis, const std::vector<sf::IntRect> &rectFrams)
    :   RectAnimation(parent, durationInMillis, rectFrams)
{
}

ErasableRectAnimation::~ErasableRectAnimation()
{

}

void ErasableRectAnimation::onAnimationComplete()
{

    parent()->setRequestDestoy(true);    
}
#include "Core/Interfaces/IAnimatable.hpp"

using namespace MoonEngine;

IAnimatable::IAnimatable(int width, int height, int top, int left, int frames, int horizontal)
    :   mWidth(width),
        mHeight(height),
        mTop(top),
        mLeft(left),
        mFrames(frames),
        mHorizontal(horizontal)
{

}

IAnimatable::~IAnimatable()
{

}

void IAnimatable::createAnimation(int startFrame)
{
    
    RectAnimation *anim = animation();

    for(int i = 0; i < mFrames; ++i)
    {
        anim->addRect(sf::IntRect(i * mHorizontal + mLeft, mTop, mWidth, mHeight));
    }

    anim->setRect(startFrame == -1 ? rand() % mFrames : startFrame);
}

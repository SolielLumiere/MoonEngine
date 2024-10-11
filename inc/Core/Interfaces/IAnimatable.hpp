#pragma once 
#include "Core/Components/Animation/RectAnimation.hpp"


namespace MoonEngine
{
    class IAnimatable
    {
    
    public:
        virtual ~IAnimatable();
        
    protected:
        IAnimatable(int width, int height, int top, int left, int frames, int horizontal);
        virtual void createAnimation(int startFrame = 0);

        virtual RectAnimation* animation() = 0;

    private:
        const int mWidth;
        const int mHeight;
        const int mTop;
        const int mLeft;
        const int mFrames;
        const int mHorizontal;
    };
}





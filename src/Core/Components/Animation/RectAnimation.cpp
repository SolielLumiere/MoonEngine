#include "Core/Components/Animation/RectAnimation.hpp"


MoonEngine::RectAnimation::RectAnimation(GameObject *parent, float durationInMillis, const std::vector<sf::IntRect> &rectFrams)
:       Component(parent),
        mDurationInSeconds(durationInMillis / 1000),
        mRectFrames(rectFrams),
        mCurrentTime(0),
        mCurrentIndex(0)
{
}

MoonEngine::RectAnimation::~RectAnimation()
{
}

void MoonEngine::RectAnimation::update(float dt)
{
    if(mRectFrames.size() == 0) return;

    mCurrentTime += dt;

    if(mCurrentTime >= mDurationInSeconds)
    {
        mCurrentIndex = mCurrentIndex + 1;

        if(mCurrentIndex >= mRectFrames.size())
        {
            mCurrentIndex = 0;
            onAnimationComplete();
        }

        parent()->setTextureRect(mRectFrames.at(mCurrentIndex));
        mCurrentTime = 0;
    }
}

void MoonEngine::RectAnimation::setRect(int index)
{
    if(index < 0 || index >= mRectFrames.size()) return;

    mCurrentIndex = index;
    parent()->setTextureRect(mRectFrames.at(index));
}

void MoonEngine::RectAnimation::setLastRect()
{
    parent()->setTextureRect(mRectFrames.back());
}

void MoonEngine::RectAnimation::onAnimationComplete()
{

}

void MoonEngine::RectAnimation::addRect(const sf::IntRect &frameRect)
{
    mRectFrames.push_back(frameRect);
}


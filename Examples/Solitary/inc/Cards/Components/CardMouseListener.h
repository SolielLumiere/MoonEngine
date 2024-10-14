#pragma once

#include "Core/Components/Mouse/MouseListener.hpp"

class CardMouseListener : public MoonEngine::MouseListener
{
    
public:
    CardMouseListener(MoonEngine::GameObject *parent);
    ~CardMouseListener();

    void update(float dt) override;
private:
    void onMouseEnter() override;
    void onMouseExit() override;
    void onLeftButtonPressed() override;
    void onLeftButtonReleased() override;

    bool mIsButtonPressed;
};


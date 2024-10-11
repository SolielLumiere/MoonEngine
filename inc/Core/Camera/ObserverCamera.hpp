#pragma once

#include "Core/Camera/Camera.hpp"


namespace MoonEngine 
{
    class GameObject;
    
    class ObserverCamera : public Camera
    {
        
    public:
        ObserverCamera(GameObject *subject, sf::RenderWindow *window);
        ~ObserverCamera();

        void update(float dt) override;
        void draw(sf::RenderWindow *window) override;
        void handleInputs(const sf::Event &event) override;
        
    private:
        GameObject *mSubject;
        
        #ifdef ENABLE_FPS_COUNTER
            int mFramesCount;
            float mTimeElapsedInSeconds;
            sf::Text mFpsText;
            sf::Font mFont;
        #endif

    };
}
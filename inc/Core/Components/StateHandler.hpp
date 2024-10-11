#pragma once

#include "Core/Components/Component.hpp"
#include "Core/States/State.hpp"


namespace MoonEngine
{

    class GameObject;

    class StateHandler : public Behavior
    {
        friend class IGame;
        friend class Game;
        
    public:
        ~StateHandler();
        static StateHandler* instance();

        virtual void start();
        virtual void handleInputs(const sf::Event &event);
        virtual void update(float dt);
        virtual void draw(sf::RenderWindow *window);
        virtual void onResize(sf::RenderWindow *window) override;

        void setState(State *newState);
        void instanciate(GameObject *e);

    private:
        StateHandler();
        State *mCurrentState;       
        
        static void init();
        static StateHandler *mInstance;

    };

}


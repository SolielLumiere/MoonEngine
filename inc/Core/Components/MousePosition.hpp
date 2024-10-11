#pragma once

#include <memory>
#include "Core/Game/IGame.hpp"
#include "Core/Components/Component.hpp"

namespace MoonEngine 
{
    class MousePosition : public Behavior
    {
        friend class IGame;

    private:
        static std::unique_ptr<MousePosition> mInstance;
        
        static void init(IGame *game);
        MousePosition(IGame *game);

        IGame *mIGame;
        
    public:
        ~MousePosition();
        static MousePosition *instance();
        sf::Vector2i position() const;
    };

}


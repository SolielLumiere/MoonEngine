#pragma once

#include "SFML/Graphics/Texture.hpp"

#define VERIFY_LOAD(x) if(!x)exit(-1)

namespace MoonEngine
{
    class Texture
    {
        
    public:
        ~Texture();
        virtual void init() = 0;

    protected:
        Texture();
    };
}

#pragma once

#include "Core/Textures/Texture.hpp"

#include <vector>

namespace MoonEngine
{

    class TextureLoader
    {
        
    public:
        TextureLoader(const std::vector<Texture*> textures);
        ~TextureLoader();
        void init();
    private:
        std::vector<Texture*> mTextures;
    };

}
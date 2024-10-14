#pragma once

#include "SFML/Graphics/Texture.hpp"
#include <list>
#define VERIFY_LOAD(x) if(!x)exit(-1)

namespace MoonEngine
{
    class Texture
    {
        
    public:
        ~Texture();
        virtual void init();
        const sf::Texture& getTextureByIndex(int index) const;

    protected:
        Texture();
        void addTexturePath(const std::string &path);
    private:
        std::vector<sf::Texture> mTextures;
        std::list<std::string> mPaths;
    };
}

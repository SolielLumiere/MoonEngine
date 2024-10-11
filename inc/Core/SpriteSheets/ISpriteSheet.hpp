#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace MoonEngine 
{
    class ISpriteSheet
    {
        
    public:
        virtual ~ISpriteSheet();
        virtual void createSprite(unsigned int id, int top, int left, int width, int height) = 0;
        virtual sf::Sprite &getSprite(unsigned int id) = 0;

    protected:
        ISpriteSheet(const std::string &path);
        sf::Texture mTexture;
        std::unordered_map<int, sf::Sprite> mSprites;
    };

}


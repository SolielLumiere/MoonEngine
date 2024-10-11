#include "Core/SpriteSheets/SpriteSheet.hpp"

using namespace MoonEngine;


SpriteSheet::SpriteSheet(const std::string &path)
    :   ISpriteSheet(path)
{
}
SpriteSheet::~SpriteSheet()
{
}
void SpriteSheet::createSprite(unsigned int id, int top, int left, int width, int height)
{
    mSprites[id] = sf::Sprite(mTexture);
    mSprites[id].setTextureRect(sf::IntRect(top, left, width, height));
}

sf::Sprite &SpriteSheet::getSprite(unsigned int id)
{
    if(mSprites.count(id) == 0)
    {
        throw "NO SPRITE CREATED WITH ID " + id;
    }

    return mSprites.at(id);
}

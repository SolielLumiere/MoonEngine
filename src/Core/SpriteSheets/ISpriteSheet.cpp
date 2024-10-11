#include "Core/SpriteSheets/ISpriteSheet.hpp"

using namespace MoonEngine;

ISpriteSheet::ISpriteSheet(const std::string &path)
{
    if(!mTexture.loadFromFile(path))
    {
        throw "FAILED TO LOAD FILE: " + path;
    }
}

ISpriteSheet::~ISpriteSheet()
{
}
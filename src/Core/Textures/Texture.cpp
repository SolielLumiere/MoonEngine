#include "Core/Textures/Texture.hpp"



using namespace MoonEngine;


Texture::Texture()
{

}


Texture::~Texture()
{

}

void MoonEngine::Texture::init()
{
    for(const std::string &path : mPaths)
    {
        sf::Texture t;
        VERIFY_LOAD(t.loadFromFile(path));
        mTextures.push_back(t);
    }
}

const sf::Texture& MoonEngine::Texture::getTextureByIndex(int index) const
{
    static sf::Texture _;
    if(index >= 0 && index < mTextures.size())
    {
        return mTextures.at(index);
    }


    printf("[WARNING]: TEXTURE NOT FOUND %s %s \n\r", __FILE__, __LINE__);

    return _;
}
void MoonEngine::Texture::addTexturePath(const std::string &path)
{
    mPaths.push_back(path);
}

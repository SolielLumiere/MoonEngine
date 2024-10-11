#include "Core/Textures/TextureLoader.hpp"

using namespace MoonEngine;

TextureLoader::TextureLoader(const std::vector<Texture *> textures)
    :   mTextures(textures)
{
}

TextureLoader::~TextureLoader()
{

}

void TextureLoader::init()
{
    for(Texture *t : mTextures)
    {
        t->init();
    }
}

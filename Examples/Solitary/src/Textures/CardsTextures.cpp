#include "Textures/CardsTextures.hpp"


CardsTextures::CardsTextures()
{
    addTexturePath("../../../Examples/Solitary/assets/solitary.png");
}

CardsTextures::~CardsTextures()
{
}

void CardsTextures::init()
{
    Texture::init();
    for(int i = 1; i < CV_TOTAL; ++i)
    {
        mDeck[CH_SPADE][static_cast<CardValue>(i)][BLACK] = sf::IntRect((i - 1) * 71, 0, 71, 96);
    }

    for(int i = 1; i < CV_TOTAL; ++i)
    {
        mDeck[CH_HEART][static_cast<CardValue>(i)][RED] = sf::IntRect((i - 1) * 71, 96, 71, 96);
    }

    for(int i = 1; i < CV_TOTAL; ++i)
    {
        mDeck[CH_CLUB][static_cast<CardValue>(i)][BLACK] = sf::IntRect((i - 1) * 71, 192, 71, 96);
    }

    for(int i = 1; i < CV_TOTAL; ++i)
    {
        mDeck[CH_DIAMOND][static_cast<CardValue>(i)][RED] = sf::IntRect((i - 1) * 71, 288, 71, 96);
    }
}

sf::IntRect CardsTextures::getCardRect(CardClass classCard, CardColor color, CardValue value)
{
    return mDeck.at(classCard).at(value).at(color);
}

const sf::Texture &CardsTextures::texture()
{
    return getTextureByIndex(0);
}

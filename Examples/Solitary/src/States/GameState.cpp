#include "States/GameState.h"
#include "Textures/CardsTextures.hpp"


GameSate::GameSate()
{
    createCards();

    addGameObject(getCard(CardClass::CH_DIAMOND, CardValue::KING, CardColor::RED));
}

GameSate::~GameSate()
{

}
void GameSate::createCards()
{
    createCardClass(CardClass::CH_CLUB, CardColor::BLACK);
    createCardClass(CardClass::CH_DIAMOND, CardColor::RED);
    createCardClass(CardClass::CH_SPADE, CardColor::BLACK);
    createCardClass(CardClass::CH_HEART, CardColor::RED);
}
void GameSate::createCardClass(CardClass cardClass, CardColor color)
{
    for(int i = 1; i < CardValue::CV_TOTAL; ++i)
    {
        CardValue v = static_cast<CardValue>(i);
        mDeck[cardClass][v][color] = new Card(cardClass, color, v, CardsTextures::instance()->texture(), CardsTextures::instance()->getCardRect(cardClass, color, v));
    }
}
Card *GameSate::getCard(CardClass cardClass, CardValue value, CardColor color)
{
    return mDeck.at(cardClass).at(value).at(color);
}
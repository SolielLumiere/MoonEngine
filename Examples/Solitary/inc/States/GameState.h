#pragma once

#include "Core/States/State.hpp"
#include "Cards/Card.h"


typedef std::unordered_map<CardClass, std::unordered_map<CardValue, std::unordered_map<CardColor, Card*>>> CardDeck;

class GameSate : public MoonEngine::State
{
    
public:
    GameSate();
    ~GameSate();


private:
    void createCards();
    void createCardClass(CardClass cardClass, CardColor color);
    Card* getCard(CardClass cardClass, CardValue value, CardColor color);
    CardDeck mDeck;
};

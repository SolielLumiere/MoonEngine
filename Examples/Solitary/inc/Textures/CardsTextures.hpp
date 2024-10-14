#pragma once

#include <unordered_map>
#include "Core/Textures/Texture.hpp"
#include "Core/Templates/Singleton.hpp"
#include "Core/SpriteSheets/SpriteSheet.hpp"
#include "Cards/Types.hpp"

typedef std::unordered_map<CardClass, std::unordered_map<CardValue, std::unordered_map<CardColor, sf::IntRect>>> Deck;


class CardsTextures : public MoonEngine::Texture, public MoonEngine::Singleton<CardsTextures>
{
    friend class MoonEngine::Singleton<CardsTextures>;

public:
    CardsTextures();
    ~CardsTextures();

    void init() override;

    sf::IntRect getCardRect(CardClass classCard, CardColor color, CardValue value);
    const sf::Texture &texture();
private:
    const int MAX_ROWS_CARDS = 4;
    const int MAX_COLS_CARDS = 13;
    Deck mDeck;

};


#include "Cards/Card.h"
#include "Cards/Types.hpp"
#include "Core/Components/Colliders/BoxCollider.hpp"
Card::Card( CardClass classCard, 
            CardColor color, 
            CardValue value, 
            const sf::Texture &texture, 
            const sf::IntRect &textureRec)
    :   GameObject(Tags::T_CARD, texture, 0),
        mClassCard(classCard),
        mColor(color),
        mValue(value)

{
    setTextureRect(textureRec);

    setCenterOrigin();
    setPosition(100, 100);

    addComponent(new MoonEngine::BoxCollider(this, (sf::Vector2f)getTextureRect().getSize()));
}

Card::~Card()
{
}

void Card::update(float dt)
{
    
}


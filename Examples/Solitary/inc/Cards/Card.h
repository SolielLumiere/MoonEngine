#pragma once 

#include "Types.hpp"
#include "Core/GameObject/GameObject.hpp"

class Card : public MoonEngine::GameObject
{
    
public:
    Card(   CardClass classCard, 
            CardColor color, 
            CardValue value, 
            const sf::Texture &texture, 
            const sf::IntRect &textureRec);
    ~Card();


    void update(float dt) override;


private:
    CardClass mClassCard;
    CardColor mColor;
    CardValue mValue;

};


#include <stdio.h>
#include "Core/Game/Game.hpp"
#include "Cards/Card.h"
#include "States/GameState.h"
#include "Core/Components/StateHandler.hpp"
#include "Core/Textures/TextureLoader.hpp"
#include "Textures/CardsTextures.hpp"
using namespace MoonEngine;


int main(int, char**)
{
    MoonEngine::TextureLoader loader({CardsTextures::instance()});
    loader.init();

    Game g(500, 500, "Solitary");
    
    StateHandler::instance()->setState(new GameSate());
    g.start();
}

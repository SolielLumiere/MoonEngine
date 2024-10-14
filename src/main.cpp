#include <stdio.h>
#include "Core/Game/Game.hpp"
using namespace MoonEngine;

int main(int, char**){

    MoonEngine::Game *g = new MoonEngine::Game(500, 500, "Title");
    g->start();
}

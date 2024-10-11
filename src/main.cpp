#include <stdio.h>
#include "Core/Game/Game.hpp"

int main(int, char**){

    MoonEngine::Game *g = new MoonEngine::Game(500, 500, "Title");
    g->start();
    

    printf("Hello, from SunEngine!\n");
}

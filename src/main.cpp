#include "game.hpp"
#include <iostream>

int main()
{
    Game game;

    while (game.is_window_open()) 
    {
            game.update();
            game.render();     
    }  

    return 0;
}
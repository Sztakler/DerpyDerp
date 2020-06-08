#include "game.hpp"
#include <iostream>

int main()
{
    std::cout << "Miłego grania w Derpy Derpa xD" << std::endl;

//Inicjalizacja gry
    Game game;

    //Game loop
    while (game.is_window_open()) //60 fps 4K
    {
            game.update();
            game.render();     
    }  

    return 0;
}
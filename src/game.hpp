#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h>
#include <iostream>
#include "entity.hpp"
#include "updater.hpp"
#include "renderer.hpp"

/*
    Klasa przechowujące główną funkcjonalność gry
*/

class Game
{
    
    private:
        sf::RenderWindow* window;
        sf::VideoMode videomode;
        sf::Event event;
        sf::Color colors[18] = 
           {sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Color(0, 0, 255),
            sf::Color(255, 255, 0), sf::Color(0, 255, 255), sf::Color(255, 0, 255),
            sf::Color(0, 0, 0), sf::Color(255, 128, 0), sf::Color(102, 51, 0),
            sf::Color(200, 70, 0), sf::Color(231, 26, 173), sf::Color(102, 51, 63),
            sf::Color(47, 46, 23), sf::Color(255, 60, 128), sf::Color(102, 51, 255),
            sf::Color(0, 43, 150), sf::Color(200, 108, 30), sf::Color(133, 14, 100)
           };

    private:
        static const int FPS = 60;
        static const int number_of_enemies = 10;
        static const int ammount_of_food = 20;
        static const int number_of_buffs = 5; 
        std::vector<Enemy*> enemies;
        std::vector<Food*> food;
        Player* player;
        Updater updater;
        Renderer renderer;
   
    public:
        static const int screen_height = 1080;
        static const int screen_width = 1920;

    public:
        Game();
       ~Game();

    public:
        void poll_events();
        void update();
        void render();

        const bool is_window_open() const;

    private:
        void initialize_variables();
        void initialize_window();
    
};



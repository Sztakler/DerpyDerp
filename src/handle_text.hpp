#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class HandleText
{
    public:
        sf::Text text;
        sf::Font font;
        static const int screen_height = 1080;
        static const int screen_width = 1920;
 
    public:
        HandleText();
        ~HandleText();
        void set_text(std::string, int, double, double, sf::Color);
};
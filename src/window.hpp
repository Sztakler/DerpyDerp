#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window : sf::RenderWindow
{
    private:
        sf::RenderWindow* render_window;
        sf::VideoMode videomode;

    public:
        Window();
        ~Window();

    public:
        const bool is_window_open() const;
        void initialize_window(int FPS);
        sf::RenderWindow* get_render_window();
};
#include "window.hpp"

Window::Window()
{
    this->render_window = nullptr;
}

Window::~Window()
{
    delete this->render_window;
}

void Window::initialize_window(int FPS)
{
    this->videomode = sf::VideoMode::getDesktopMode();
    this->render_window = new sf::RenderWindow(videomode, "Derpy Derp", sf::Style::Fullscreen);
    this->render_window->setFramerateLimit(FPS); 
}

const bool Window::is_window_open() const
{                                       
    return this->render_window->isOpen();
}

sf::RenderWindow* Window::get_render_window()
{
    return this->render_window;
}
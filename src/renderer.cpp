#include "renderer.hpp"

Renderer::Renderer(){}

Renderer::~Renderer(){}

void Renderer::render(Player* player, std::vector<Enemy*>& enemies, std::vector<Food*>& food, sf::RenderWindow* window, sf::Text text)
{
    window->clear(sf::Color(255, 255, 255));

    this->render_player(player, window);
    this->render_enemies(enemies, window);
    this->render_food(food, window);
    window->draw(text);
    window->display();
}

void Renderer::render_player(Player* player, sf::RenderWindow* window)
{
    window->draw(*player);
}

void Renderer::render_enemies(std::vector<Enemy*>& enemies, sf::RenderWindow* window)
{
    for (Enemy* enemy : enemies)
    {
        window->draw(*enemy);
    }
}

void Renderer::render_food(std::vector<Food*>& food, sf::RenderWindow* window)
{
    for (Food* buff : food)
    {
        window->draw(*buff);
    }
}


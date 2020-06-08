#include "player.hpp"
#include "enemy.hpp"
#include "food.hpp"


class Renderer
{
    public:
        Renderer();
        ~Renderer();
        void render(Player*, std::vector<Enemy*>&, std::vector<Food*>&, sf::RenderWindow*, sf::Text);
        void render_player(Player*, sf::RenderWindow*);
        void render_enemies(std::vector<Enemy*>&, sf::RenderWindow*);
        void render_food(std::vector<Food*>&, sf::RenderWindow*);
};
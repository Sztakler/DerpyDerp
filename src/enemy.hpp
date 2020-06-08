#pragma once

#include "entity.hpp"
#include <SFML/Graphics.hpp>

class Enemy : public Entity
{
    public:
      const double max_speed = 0.006;
      const double min_speed = 0.002;
        //Rysowanie kształtów umożliwione dzięki dziedziczeniu z klas bazowych SFML'a
        //https://en.sfml-dev.org/forums/index.php?topic=18179.0
    private:
      virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    public: 
        Enemy();
        Enemy(float size, double speed, sf::Color color);
        ~Enemy();

};
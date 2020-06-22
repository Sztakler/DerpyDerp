#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class Entity : public sf::Sprite
{
    protected:
        float size;
        sf::CircleShape circle;
        sf::Color color;

    protected:
        Entity();
        Entity(float, double, sf::Color);
  
    public:
      double speed;

      //Rysowanie kształtów umożliwione dzięki dziedziczeniu z klas bazowych SFML'a
      //https://en.sfml-dev.org/forums/index.php?topic=18179.0
      private:
      virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;

    public:    
        float get_radius();
        virtual void grow(float r);
        int is_collision(Entity*);
};
#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Food : public Entity
{
    private:
      enum Effects {haste, slowness, increase, regular};
      sf::Color Colors[4] {sf::Color (168, 25, 154), 
                           sf::Color(210, 25, 25),
                           sf::Color(3, 179, 32),
                           sf::Color(0, 0, 0)}; //purple, red, green, black
      int effect;

    private:
      virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

    public:
      bool eaten;
      
    public:
      Food();
      Food(int effect);
      ~Food(); 

    public:
      Effects get_effect(); 

};
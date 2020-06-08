#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <cmath>

class Player : public Entity
{
    private:
        sf::Color outline_color;

    public:
        const double max_speed = 7.0;
        const double min_speed = 3.0;
    
    private:
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    public:
        Player();
        Player(float size, double speed, sf::Color color, sf::Color outline_color);
        ~Player();

    public:    
        void kill();
};

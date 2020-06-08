#include "food.hpp"

Food::Food(int effect) : Entity(5, 0, Colors[effect])
{
    this->effect = effect;
    this->eaten = false;
    this->circle = sf::CircleShape(5);
    this->circle.setFillColor(Colors[effect]);
}

Food::~Food(){}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform = getTransform();
            target.draw(circle, states);
        }

Food::Effects Food::get_effect()
{
    return Effects(this->effect);
}
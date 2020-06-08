#include "player.hpp"

Player::Player(){}

Player::Player(float size, double speed, sf::Color color, sf::Color outline_color) : Entity(size, speed, color), outline_color(outline_color)
{
    this->circle = sf::CircleShape(size);
    this->circle.setFillColor(color);
    this->circle.setOutlineColor(outline_color);
    this->circle.setOutlineThickness(7);
}

Player::~Player() = default;

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform = getTransform();
            target.draw(circle, states);
        }

void Player::kill()
{
    this->circle.setRadius(0);
}

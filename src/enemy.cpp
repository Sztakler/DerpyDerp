#include "enemy.hpp"

Enemy::Enemy(float size, double speed, sf::Color color) : Entity(size, speed, color)
{
    this->circle = sf::CircleShape(size);
    this->circle.setFillColor(color);
}

Enemy::~Enemy(){}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform = getTransform();
            target.draw(circle, states);
        }
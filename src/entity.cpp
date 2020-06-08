#include "entity.hpp"

Entity::Entity(){}
Entity::Entity(float size, double speed, sf::Color color) : size(size), speed(speed), color(color){}

float Entity::get_radius()
{
    return this->circle.getRadius();
}

void Entity::grow(float r)
{
    this->circle.setRadius(this->circle.getRadius() + (r / 4));
    this->size = this->circle.getRadius() + (r / 4);
}

int Entity::is_collision(Entity* entity)
{
    float self_x        = this->getPosition().x;
    float self_y        = this->getPosition().y;
    float entity_x      = entity->getPosition().x;
    float entity_y      = entity->getPosition().y;
    float self_radius   = this->get_radius();
    float entity_radius = entity->get_radius();

    float distance = sqrt(pow((float)((self_x + self_radius) - (entity_x + entity_radius)), 2) + 
                          pow(((self_y + self_radius) - (entity_y + entity_radius)), 2));

    if (distance < self_radius + entity_radius)
    {
        if (self_radius >= entity_radius) return 1; //wygrywa self
        if (self_radius < entity_radius)  return 2; //wygrywa entity
    }
    return 0;                                       //brak kolizji
}                                                  
#include <iostream>
#include "updater.hpp"

Updater::Updater()
{
    this->text = HandleText();
}

Updater::~Updater(){}


void Updater::update(Player* player, std::vector<Enemy*>& enemies, std::vector<Food*>& food)
{
    this->update_player(player, enemies, food);
    this->update_enemies(enemies, food);
    this->update_food(food);
}

void Updater::update_player(Player* player, std::vector<Enemy*>& enemies, std::vector<Food*>& food)
{
    float pos_x = player->getPosition().x;
    float pos_y = player->getPosition().y;

    if (pos_x < 0) player->setPosition((int)pos_x + screen_width, (int)pos_y);
    if (pos_x > screen_width) player->setPosition((int)pos_x % screen_width, (int)pos_y);
    if (pos_y < 0) player->setPosition((int)pos_x, (int)pos_y + screen_height);
    if (pos_y > screen_height) player->setPosition((int)pos_x, (int)pos_y % screen_height);


    for(int i = 0; i < enemies.size(); i++)
    {
        switch (player->is_collision(enemies[i]))
        {
            case 1:
                player->grow(enemies[i]->get_radius());
                enemies.erase(enemies.begin() + i);
                break;
            case 2:
                this->text.set_text("PRZEGRANKO", 100, screen_width, screen_height, sf::Color::Black);
                player->kill();
                break;
            default: 
                break;
        }
    }

    for(int i = 0; i < food.size(); i++)
        {
            if (player->is_collision(food[i]))
            {
                food[i]->eaten = true;

                switch (food[i]->get_effect())
                {
                    case 0: //haste
                        if(player->speed + 2 <= player->max_speed) 
                            player->speed += 2; 
                        break;
                    case 1: //slowness
                        if(player->speed - 2 >= player->min_speed) 
                            player->speed -= 2; 
                        break;
                    case 2: //increase
                        player->grow(20); 
                        break;
                    case 3: //regular
                        player->grow(food[i]->get_radius()); 
                        break;
                    default:
                        break;
                }
            }
        }
}

void Updater::update_food(std::vector<Food*>& food)
{
    srand(time(NULL));
    for (int j = 0; j < food.size(); j++)
    {
        Food* buff = food[j];
        float dx = (float)(rand() % 1000 - 500) / 250;
        float dy = (float)(rand() % 1000 - 500) / 250;
        float pos_x = buff->getPosition().x;
        float pos_y = buff->getPosition().y;
        float r = buff->get_radius();

        if (buff->eaten)
        {
            food.erase(food.begin() + j);
            int effect = rand() % 4;
            int x = rand() % screen_width;
            int y = rand() % screen_height;
            food.push_back(new Food(effect));
            food.back()->setPosition(x, y);
        }
    }
}

void Updater::update_enemies(std::vector<Enemy*>& enemies, std::vector<Food*>& food)
{
    srand(time(NULL));
    for (int j = 0; j < enemies.size(); j++)
    {
        Enemy* enemy = enemies[j];
        float dx = (float)(rand() % 1000 - 500) * enemy->speed;
        float dy = (float)(rand() % 1000 - 500) * enemy->speed;
        float pos_x = enemy->getPosition().x;
        float pos_y = enemy->getPosition().y;
        float r = enemy->get_radius();

        if (pos_x + r < 0)   enemy->setPosition((int)pos_x + screen_width, (int)pos_y);
        if (pos_x + r> screen_width) enemy->setPosition((int)pos_x % screen_width, (int)pos_y);
        if (pos_y + r < 0)   enemy->setPosition((int)pos_x, (int)pos_y + screen_height);
        if (pos_y + r > screen_height) enemy->setPosition((int)pos_x, (int)pos_y % screen_height);

        for(int i = 0; i < enemies.size(); i++)
        {
            if (enemy != enemies[i])
            {
                switch (enemy->is_collision(enemies[i]))
                {
                    case 1:
                        enemy->grow(enemies[i]->get_radius());
                        enemies.erase(enemies.begin() + i);
                        break;
                    case 2:
                        enemies[i]->grow(enemy->get_radius());
                        enemies.erase(enemies.begin() + j);
                        break;
                    default: 
                        break;
                }
            }
        }

        for(int i = 0; i < food.size(); i++)
        {
            if (enemy->is_collision(food[i]))
            {
                food[i]->eaten = true;

                switch (food[i]->get_effect())
                {
                    case 0: 
                        if(enemy->speed + 0.001 <= enemy->max_speed) 
                            enemy->speed += 0.001; //haste
                        break;
                    case 1: 
                    if(enemy->speed + 0.001 >= enemy->min_speed) 
                        enemy->speed -= 0.001; //slowness
                        break;
                    case 2: 
                        enemy->grow(20); //increase
                        break;
                    case 3: 
                        enemy->grow(food[i]->get_radius()); //regular
                        break;
                    default:
                        break;
                }
            }
                    
        }

        enemy->move(dx, dy);   
    }
}
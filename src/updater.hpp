#pragma once
#include <vector>
#include "entity.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "food.hpp"
#include "handle_text.hpp"

class Updater
{

    public:
        static const int screen_height = 1080;
        static const int screen_width = 1920;
        HandleText text;
    public:
        Updater();
        ~Updater();
        void update(Player* player, std::vector<Enemy*>& enemies, std::vector<Food*>& food);
        void update_enemies(std::vector<Enemy*>& enemies, std::vector<Food*>& food);
        void update_food(std::vector<Food*>& food);
        void update_player(Player* player, std::vector<Enemy*>& enemies, std::vector<Food*>& food);
};
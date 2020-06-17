#pragma once

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <cmath>

/* 
Klasa realizuje wzorzec projektowy Singleton. Zawiera prywatne konstruktory, używane tylko raz do utworzenia pola 
"instance", przechowującego pojedynczą instancję klasy. Metoda "get_instance()" zwraca wskaźnik do tej instancji.
*/

class Player : public Entity
{
    private:
        sf::Color outline_color;
        static Player* player_instance;

    public:
        const double max_speed = 7.0;
        const double min_speed = 3.0;
    
    private:
        Player();
        Player(float size, double speed, sf::Color color, sf::Color outline_color);
        Player(const Player&);
        Player& operator= (const Player&);
        ~Player();

    private:
        virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    
    public:
        static Player* get_instance();
        void kill();
};

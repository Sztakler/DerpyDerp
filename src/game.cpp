#include "game.hpp"

Game::Game()
{
    this->initialize_variables();
    this->initialize_window();
}

Game::~Game()
{
    delete this->window;
}

//Funkcje prywatne
void Game::initialize_variables()
{
    srand(time(NULL));
    this->window = nullptr;

    float x = rand() % screen_width;
    float y = rand() % screen_height;
    this->player = new Player(25.f, 5.0, sf::Color::White, sf::Color::Blue);
    this->player->setPosition(x, y);

    
    for (int i = 0; i < number_of_enemies; i++)
    {  
        int size = rand() % 35 + 10;
        x = rand() % screen_width;
        y = rand() % screen_height;
        int j = rand() % 18;
        this->enemies.push_back(new Enemy(size, 0.004, this->colors[j]));
        this->enemies[i]->setPosition(x, y);
    }

    for (int i = 0; i < ammount_of_food; i++)
    {  
        x = rand()  % screen_width;
        y = rand()  % screen_height;
        this->food.push_back(new Food(3));
        this->food[i]->setPosition(x, y);
    }

    for (int i = 0; i < number_of_buffs; i++)
    {  
        int effect = 1;
        x = rand()  % screen_width;
        y = rand()  % screen_height;
        this->food.push_back(new Food(effect));
        this->food[i + ammount_of_food]->setPosition(x, y);
    }
}

void Game::initialize_window()
{
    this->videomode = sf::VideoMode::getDesktopMode();
    this->window = new sf::RenderWindow(videomode, "Derpy Derp", sf::Style::Fullscreen);
    this->window->setFramerateLimit(FPS); 
}

//Funkcje publiczne

void Game::poll_events()
{
    //-----------------------------------------------------//

    // PLAYER MOVEMENT
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*window));
   
    float player_x = player->getPosition().x;
    float player_y = player->getPosition().y;

    float dx = std::min((mouse_pos.x - player_x) * 0.05, 1.0);
    float dy = std::min((mouse_pos.y - player_y) * 0.05, 1.0);

    if ((mouse_pos.y - player_y) * 0.05 >  player->speed) dy =  player->speed;
    if ((mouse_pos.x - player_x) * 0.05 >  player->speed) dx =  player->speed;
    if ((mouse_pos.y - player_y) * 0.05 < -player->speed) dy = -player->speed;
    if ((mouse_pos.x - player_x) * 0.05 < -player->speed) dx = -player->speed;

    this->player->move(dx, dy);

    //-----------------------------------------------------//

    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) this->window->close();
                break;
            default:
                break;
        }
    }
}

void Game::update()
{
    poll_events();
    this->updater.update(player, enemies, food);
}

void Game::render()
{
    this->renderer.render(player, enemies, food, window, this->updater.text.text);
}

    //Akcesor
const bool Game::is_window_open() const //const member function - nie zmienia
{                                       //wartości składowych klasy
    return this->window->isOpen();
}
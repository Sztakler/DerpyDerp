#include "game.hpp"

Game::Game()
{
    this->initialize_variables();
    this->window->initialize_window(this->FPS);
}

Game::~Game()
{
    delete this->window;
}

void Game::initialize_variables()
{
    srand(time(NULL));
    this->window = new Window();

    float x = rand() % screen_width;
    float y = rand() % screen_height;
    this->player = Player::get_instance();
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


void Game::poll_events()
{
    sf::Vector2f mouse_pos = sf::Vector2f(sf::Mouse::getPosition(*this->window->get_render_window()));
   
    float player_x = player->getPosition().x;
    float player_y = player->getPosition().y;

    float dx = std::min((mouse_pos.x - player_x) * 0.05, 1.0);
    float dy = std::min((mouse_pos.y - player_y) * 0.05, 1.0);

    if ((mouse_pos.y - player_y) * 0.05 >  player->speed) dy =  player->speed;
    if ((mouse_pos.x - player_x) * 0.05 >  player->speed) dx =  player->speed;
    if ((mouse_pos.y - player_y) * 0.05 < -player->speed) dy = -player->speed;
    if ((mouse_pos.x - player_x) * 0.05 < -player->speed) dx = -player->speed;

    this->player->move(dx, dy);

    while (this->window->get_render_window()->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->get_render_window()->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) this->window->get_render_window()->close();
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
    this->renderer.render(player, enemies, food, window->get_render_window(), this->updater.text_field.text);
}

const bool Game::is_window_open() const
{                                       
    return this->window->is_window_open();
}
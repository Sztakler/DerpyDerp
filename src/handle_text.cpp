#include "handle_text.hpp"

HandleText::HandleText()
{
    this->text = sf::Text();
    if (!this->font.loadFromFile("fonts/Montserrat-Black.ttf"))
    {
        throw std::runtime_error("No such font");
    }
}
HandleText::~HandleText(){}

void HandleText::set_text(std::string text, int size, double pos_x, double pos_y, sf::Color color)
{
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(size);
    this->text.setPosition((screen_width  - this->text.getGlobalBounds().width)  / 2, 
                           (screen_height - this->text.getGlobalBounds().height) / 2);
    this->text.setFillColor(color);

}
#include "Score.h"


Score::Score()
{
    value = 0;
    font.loadFromFile("fonts//Flappy-Bird.ttf");
    s.setFont(font);
    s.setPosition(10, 0);
    s.setOutlineThickness(3);
    s.setCharacterSize(60);
}

void Score::draw(sf::RenderWindow& w)
{
    s.setString(std::to_string(value));
    w.draw(s);
}

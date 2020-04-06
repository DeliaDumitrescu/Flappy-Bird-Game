#include "Pipes.h"

Pipe::Pipe()
{
    t_up.loadFromFile("Images//Pipe_up.png");
    t_down.loadFromFile("Images//Pipe_down.png");
    s_up.setTexture(t_up); s_up.setOrigin(0, y); s_up.setPosition(x, 0);
    s_down.setTexture(t_down); /*s_up.setOrigin(0, y);*/ s_down.setPosition(x, 1000 - y);
};

void Pipe::draw(sf::RenderWindow &window)
{
    s_up.setOrigin(0, y); s_up.setPosition(x, 0);
    s_down.setPosition(x, 1000 - y);
    window.draw(s_up);
    window.draw(s_down);
}

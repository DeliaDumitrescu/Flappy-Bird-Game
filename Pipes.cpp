#include "Pipes.h"

int Pipe::reset_x = 600;

Pipe::Pipe()
{
    x = 600;
    y = rand() % 400 + 350;
    t_up.loadFromFile("images//Pipe_up.png");
    t_down.loadFromFile("images//Pipe_down.png");
    s_up.setTexture(t_up); s_up.setOrigin(0, y); s_up.setPosition(x, 0);
    s_down.setTexture(t_down); /*s_up.setOrigin(0, y);*/
    s_down.setPosition(x, 1000 - y);
}

void Pipe::draw(sf::RenderWindow &window)
{
    s_up.setOrigin(0, y); s_up.setPosition(x, 0);
    s_down.setPosition(x, 1000 - y);
    window.draw(s_up);
    window.draw(s_down);
}

void Pipe::reset()
{
    x = reset_x;
    y = rand() % 400 + 350;
    reset_x += 500;
    if(x == 1600)
        reset_x = 600;
}
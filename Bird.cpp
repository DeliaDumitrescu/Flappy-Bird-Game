#include "Bird.h"

Bird::Bird()
{
    t.loadFromFile("images//bird.png");
    s.setTexture(t);
    buffer.loadFromFile("sounds//flap.wav");
    flap_sound.setBuffer(buffer);
    x = 120;
    y = 500;
    s.setPosition(x, y);
    s.setOrigin(30, 22);
    alive = 1;
    dy = 0;
    angle = 0;
}

void Bird::fall()
{
    dy += 0.1;
    y += dy;
    if(dy<0)
        angle = -30;
    else
        angle = 20;
}

void Bird::jump()
{
    dy = -4;
    angle = -30;
    flap_sound.play();
}

void Bird::draw(sf::RenderWindow& w)
{
    s.setPosition(x, y);
    s.setRotation(angle);
    w.draw(s);
}

void Bird::reset()
{
    x = 120;
    y = 500;
    dy = 0;
    alive = 1;
    angle = 0;
}

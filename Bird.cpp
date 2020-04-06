#include "Bird.h"
#include <bits/stdc++.h>


Bird::Bird()
{
    t.loadFromFile("Images//bird.png");
    s.setTexture(t);
    x = 120;
    y = 500;
    s.setPosition(x, y);
    s.setOrigin(30, 22);
    alive = 1;
    score = 0;
    dy = 0;
    angle = 0;
}

void Bird::fall()
{
    dy += 1;
    y += dy;
    angle = 30;
}

void Bird::jump()
{
    dy += 1;
    y -= dy;
    angle = -30;
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
    score = 0;
    angle = 0;

}

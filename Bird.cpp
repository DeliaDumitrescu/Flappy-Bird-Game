#include "Bird.h"

 Bird::Bird(int val_alive, int val_x, int val_y, int val_dy, int val_angle, std::string val_fileBird, std::string val_fileSound)
 {
    alive = val_alive;
    x = val_x;
    y = val_y;
    dy = val_dy;
    angle = val_angle;
    fileBird = val_fileBird;
    fileSound = val_fileSound;
    if(fileBird != "")
    {
        t.loadFromFile(fileBird);
        s.setTexture(t);
        s.setPosition(x, y);
        s.setOrigin(30, 22);
    }
    if(fileSound != "")
    {
        buffer.loadFromFile(fileSound);
        flap_sound.setBuffer(buffer);
    }
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

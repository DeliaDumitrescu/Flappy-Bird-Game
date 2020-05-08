#include "Bird.h"
#include <iostream>
#include <filesystem>

 Bird::Bird(std::string val_name, int val_alive, int val_x, int val_y, int val_dy, int val_angle, std::string val_fileBird, std::string val_fileSound)
 {
    name = val_name;
    alive = val_alive;
    x = val_x;
    y = val_y;
    dy = val_dy;
    angle = val_angle;
    fileBird = val_fileBird;
    fileSound = val_fileSound;
    manageExceptions();
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

Bird& Bird::operator ++(int)
{
    this->jump();
    return *this;
}

Bird& Bird::operator --(int)
{
    this->fall();
    return *this;
}

std::istream& operator >> (std::istream& in, Bird& bird)
{
    std::cout<< "Enter your bird's name and hit enter: ";
    in >> bird.name;
    return in;
}

void Bird::manageExceptions()
{
    try {
        if (std::filesystem::exists(fileBird)) throw fileBird;
        else throw 0;
    }
    catch (std::string fisier)
    {
        t.loadFromFile(fisier);
        s.setTexture(t);
        s.setPosition(x, y);
        s.setOrigin(30, 22);
    }
    catch (...) {
        std::cout << "Couldn't find file " << fileBird << " for bird\n";
    }
    try {
        if (std::filesystem::exists(fileSound)) throw fileSound;
        else throw 0;
    }
    catch (std::string fisier)
    {
        buffer.loadFromFile(fileSound);
        flap_sound.setBuffer(buffer);
    }
    catch (...) {
        std::cout << "Couldn't find file " << fileSound << " for bird\n";
    }
}
#include "Bird.h"
#include <iostream>
#include <filesystem>

Bird* Bird::instance = nullptr;

Bird* Bird::GetInstance()
{
    if (instance == nullptr) instance = new Bird();
    return instance;
}

 Bird::Bird()
 {
    name = "Your Bird";
    alive = 1;
    x = 120;
    y = 500;
    dy = 0;
    angle = 0;
    fileBird = "images//bird.png";
    fileSound = "sounds//flap.wav";
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

std::istream& operator >>(std::istream& in, Bird& bird)
{
    std::cout<< "Enter your bird's name and hit enter: ";
    in >> bird.name;
    return in;
}

void Bird::manageExceptions()
{
    try {
        if (!std::filesystem::exists(fileBird)) throw file_not_found_error(fileBird);
        else throw 1;
    }
    catch (const file_not_found_error& err) {
        std::cout << err.what() << '\n';
    }
    catch (...) {
        t.loadFromFile(fileBird);
        s.setTexture(t);
        s.setPosition(x, y);
        s.setOrigin(30, 22);
    }
    try {
        if (!std::filesystem::exists(fileSound)) throw file_not_found_error(fileSound);
        else throw 1;
    }
    catch (const file_not_found_error& err) {
        std::cout << err.what() << '\n';
    }
    catch (...) {
        buffer.loadFromFile(fileSound);
        flap_sound.setBuffer(buffer);
    }
}

bool Bird::hitsPipe(int pipe_x, int pipe_y)
{
    return x + 30 > pipe_x && (y - 22 < 800 - pipe_y || y + 22 > 1000 - pipe_y);

}


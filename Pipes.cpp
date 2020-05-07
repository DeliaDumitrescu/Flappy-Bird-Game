#include "Pipes.h"
#include <iostream>
#include <filesystem>

int Pipe::reset_x = 600;

Pipe::Pipe(int val_x, std::string val_file_up, std::string val_file_down)
{
    x = val_x;
    y = rand() % 400 + 350;
    file_up = val_file_up;
    file_down = val_file_down;
    manageExceptions();
}

Pipe::Pipe(const Pipe& other)
{
    x = other.x;
    y = other.y;
    file_up = other.file_up;
    file_down = other.file_down;

    t_up.loadFromFile(file_up);
    t_down.loadFromFile(file_down);
    s_up.setTexture(t_up); s_up.setOrigin(0, y); s_up.setPosition(x, 0);
    s_down.setTexture(t_down);
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

Pipe& Pipe::operator =(const Pipe& other)
{
    x = other.x;
    y = other.y;
    file_up = other.file_up;
    file_down = other.file_down;

    manageExceptions();
    return *this;
}

Pipe Pipe::operator +(int val) const
{
    Pipe aux(*this);
    aux.x += val;
    return aux;
}

Pipe Pipe::operator -(int val) const
{
    Pipe aux(*this);
    aux.x += val;
    return aux;
}


void Pipe::operator +=(int val)
{
    this->x += val;
}

void Pipe::operator -=(int val)
{
    this->x -= val;
}

void Pipe::manageExceptions()
{
    try {
        if (std::filesystem::exists(file_up) && std::filesystem::exists(file_down)) throw "ok";
        else throw 0;
    }
    catch (const char s[])
    {
        t_up.loadFromFile(file_up);
        t_down.loadFromFile(file_down);
        s_up.setTexture(t_up); s_up.setOrigin(0, y); s_up.setPosition(x, 0);
        s_down.setTexture(t_down);
        s_down.setPosition(x, 1000 - y);
    }
    catch (...) {
        std::cout << "Couldn't find both of the files " << file_up << " and " << file_down << " for pipes\n";
    }
}
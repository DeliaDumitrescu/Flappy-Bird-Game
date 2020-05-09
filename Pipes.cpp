#include "Pipes.h"
#include <iostream>
#include <filesystem>

int Pipe::reset_x = 600;

Pipe::Pipe(int _x, std::string _file_up, std::string _file_down)
{
    x = _x;
    y = rand() % 400 + 350;
    file_up = _file_up;
    file_down = _file_down;
    manageExceptions();
}

Pipe::Pipe(const Pipe& other)
{
    x = other.x;
    y = other.y;
    file_up = other.file_up;
    file_down = other.file_down;

    manageExceptions();
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
        if (!std::filesystem::exists(file_up) || !std::filesystem::exists(file_down)) throw Exception("Missing pipe's files!\n");
        else throw 1;
    }
    catch (const Exception& err) {
        std::cout << err.what();
    }
    catch (...) {
        t_up.loadFromFile(file_up);
        t_down.loadFromFile(file_down);
        s_up.setTexture(t_up); s_up.setOrigin(0, y); s_up.setPosition(x, 0);
        s_down.setTexture(t_down);
        s_down.setPosition(x, 1000 - y);
    }
}

void Pipe::updatePosition()
{
    if(x < -150)
    {   x = 1350;
        y = rand() % 400 + 350;
    }
}

bool Pipe::passed()
{
    return x == 5;
}
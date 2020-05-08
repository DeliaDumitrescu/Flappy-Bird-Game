#include "Text.h"
#include <iostream>
#include <filesystem>

Text::Text(int _x, int _y, int _thickness, int _size, std::string _s, std::string _fileName)
{
    fileName = _fileName;

    x = _x;
    y = _y;
    thickness = _thickness;
    size = _size;
    s = _s;

    manageExceptions();

    t.setPosition(x, y);
    t.setFont(f);
    t.setOutlineThickness(thickness);
    t.setCharacterSize(size);
    t.setString(s);
}

void Text::draw(sf::RenderWindow& w)
{
    t.setString(s);
    w.draw(t);
}

Text& Text::operator =(const Text& other)
{
    fileName = other.fileName;
    x = other.x;
    y = other.y;
    thickness = other.thickness;
    size = other.size;
    s = other.s;
    f = other.f;

    t.setPosition(x, y);
    t.setFont(f);
    t.setOutlineThickness(thickness);
    t.setCharacterSize(size);
    t.setString(s);
    return *this;
}

template<>
void Text::setText<std::string>(std::string _s)
{
    s = _s;
}

template<typename T>
void Text::setText(T _s)
{
 s = std::to_string(_s);
}

//template void Text::setText <int> (int);

void Text::manageExceptions()
{
    try {
        if (std::filesystem::exists(fileName)) throw fileName;
        else throw 0;
    }
    catch (std::string fisier) {
        f.loadFromFile(fisier);
    }
    catch (...) {
        std::cout << "Couldn't find the file " << fileName << " for text \n";
    }
}
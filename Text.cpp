#include "Text.h"
#include <iostream>
#include <filesystem>

Text::Text(int positionX, int positionY, int thicknesss, int sizee, std::string ss, std::string fileNamee)
{
    fileName = fileNamee;
    try {
        if (std::filesystem::exists(fileName)) throw fileName;
        else throw 0;
    }
    catch (std::string fisier) {
        f.loadFromFile(fisier);
    }
    catch (...) {
        std::cout << "Nu am putut gasi fisierul " << fileName << '\n';
    }
    x = positionX;
    y = positionY;
    thickness = thicknesss;
    size = sizee;
    s = ss;

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
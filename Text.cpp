#include "Text.h"
#include <iostream>
#include <filesystem>

template class Text<int>;

template <class T>
Text<T>::Text(T _x, T _y, T _thickness, T _size, std::string _s, std::string _fileName): fileName(_fileName), x(_x), y(_y), thickness(_thickness), size(_size), s(_s)
{
    manageExceptions();
    t.setPosition(x, y);
    t.setFont(f);
    t.setOutlineThickness(thickness);
    t.setCharacterSize(size);
    t.setString(s);
}

template <class T>
void Text<T>::draw(sf::RenderWindow& w)
{
    t.setString(s);
    w.draw(t);
}

template <class T>
Text<T>& Text<T>::operator =(const Text& other)
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

template <class T>
void Text<T>::manageExceptions()
{
    try {
        if (!std::filesystem::exists(fileName)) throw file_not_found_error(fileName);
        else throw 1;
    }
    catch (const file_not_found_error& err) {
        std::cout << err.what();
    }
    catch (...) {
        f.loadFromFile(fileName);
    }
}
#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objects.h"
#include "Exceptions.h"

template <class T>
class Text
{
private:
    T x, y, thickness, size;
    sf::Text t;
    sf::Font f;
    std::string s;
    std::string fileName;
public:
    Text(T _x = 0, T _y = 0, T _thickness = 0, T _size = 0, std::string _s = "", std::string _fileName = "");
    void setText(std::string _s){s = _s;}
    void draw(sf::RenderWindow&);
    Text& operator =(const Text&);
    void manageExceptions();
};


#endif
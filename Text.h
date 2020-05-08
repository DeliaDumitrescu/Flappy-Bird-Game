#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objects.h"

class Text
{
private:
    int x, y;
    sf::Text t;
    sf::Font f;
    int thickness, size;
    std::string s;
    std::string fileName;
public:
    Text(int _x = 0, int _y = 0, int _thickness = 0, int _size = 0, std::string _s = "", std::string _fileName = "");
    template <typename T> void setText(T _s);
    void draw(sf::RenderWindow&);
    Text& operator =(const Text&);
    void manageExceptions();
};


#endif
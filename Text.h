#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Objects.h"

class Text
{
private:
    float x, y;
    sf::Text t;
    sf::Font f;
    int thickness, size;
    std::string s;
    std::string fileName;
public:
    Text(int positionX = 0, int positionY = 0, int thicknesss = 0, int sizee = 0, std::string ss = "", std::string fileNamee = "");
    template <typename T> void setText(T ss);
    void draw(sf::RenderWindow&);
    Text& operator =(const Text&);
    void manageExceptions();
};


#endif
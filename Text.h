#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Text
{
private:
    sf::Text t;
    sf::Font f;
    int x, y, thickness, size;
    std::string s;
    std::string fileName;
public:
    Text(int positionX = 0, int positionY = 0, int thicknesss = 0, int sizee = 0, std::string ss = "", std::string fileNamee = "");
    void setText(std::string ss) { s = ss; }
    void draw(sf::RenderWindow&);
};


#endif
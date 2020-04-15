#include "Text.h"

Text::Text(int positionXX, int positionYY, int thicknesss, int sizee, std::string ss, std::string fileNamee)
{
    fileName = fileNamee;
    f.loadFromFile(fileNamee);
    positionX = positionXX;
    positionY = positionYY;
    thickness = thicknesss;
    size = sizee;
    s = ss;

    t.setPosition(positionX, positionY);
    t.setFont(f);
    t.setPosition(positionX, positionY);
    t.setOutlineThickness(thickness);
    t.setCharacterSize(size);
    t.setString(s);

}

void Text::draw(sf::RenderWindow& w)
{
    w.draw(t);
}
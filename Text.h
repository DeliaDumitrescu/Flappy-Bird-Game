#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>


class Text{
private:
    sf::Text t;
    sf::Font f;
    int positionX, positionY, thickness, size;
    std::string s;
    std::string fileName;
public:
    Text(int positionXX, int positionYY, int thicknesss, int sizee, std::string ss, std::string fileNamee);
    void draw(sf::RenderWindow&);
};






#endif
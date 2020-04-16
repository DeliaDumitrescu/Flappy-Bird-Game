#ifndef TEXT_H
#define TEXT_H
#include <SFML/Graphics.hpp>

class Text
{
private:
    sf::Text t;
    sf::Font f;
    int positionX, positionY, thickness, size;
    std::string s;
    std::string fileName;

public:
    Text(int positionXX = 0, int positionYY = 0, int thicknesss = 0, int sizee = 0, std::string ss = "", std::string fileNamee = "");
    void draw(sf::RenderWindow&);
};






#endif
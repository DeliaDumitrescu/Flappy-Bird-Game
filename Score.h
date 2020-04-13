#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Score {
private:
    sf::Text s;
    sf::Font font;
    int value;
public:
    Score();
    sf::Text getS() { return s; }
    void draw(sf::RenderWindow&);
    int getValue() { return value; }
    void updateValue() { value++; }
    void resetValue();
};


#endif // SCORE_H
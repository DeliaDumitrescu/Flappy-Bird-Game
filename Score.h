#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>



class Score{
private:
    sf::Text s;
    sf::Font font;
    int value;
public:
    Score();
    sf::Text getS(){return s;}
    int getValue(){return value;}
};



#endif // SCORE_H
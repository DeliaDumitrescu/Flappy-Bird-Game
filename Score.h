#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

class Score
{
private:
    sf::Text s;
    sf::Font font;
    int value;
    int positionX, positionY, thickness, size;
    std::string fileName;
    std::priority_queue <int> allScores;

public:
    Score(int valuee = 0, int positionXX = 10, int positionYY = 0, int thicknesss = 3, int sizee = 60, std::string fileNamee = "fonts//Flappy-Bird.ttf");
    Score(const Score&);
    sf::Text getS() { return s; }
    void draw(sf::RenderWindow&);
    int getValue() { return value; }
    void updateValue() { value++; }
    void resetValue();
    Score& operator ++();
    Score operator ++(int);
    void insertScore();
    //void print();
};


#endif // SCORE_H
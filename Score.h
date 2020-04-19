#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <queue>
#include "Text.h"

class Score
{
private:
    int value;
    Text scoreText{10, 0, 3, 60, "", "fonts//Flappy-Bird.ttf"};
    std::priority_queue <int> allScores;
public:
    Score(int valuee = 0) : value(valuee) {}
    Score(const Score&);
    void draw(sf::RenderWindow&);
    int getValue() const { return value; }
    int getHS() const { return allScores.empty() ? 0 : allScores.top(); }
    void updateValue() { value++; }
    void resetValue() { value = 0; }
    Score& operator ++();
    Score operator ++(int);
    void insertScore() { allScores.push(value); }
    friend std::ostream& operator << (std::ostream&, Score&);
};

#endif // SCORE_H
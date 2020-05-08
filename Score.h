#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <queue>
#include "Text.h"
#include "Pipes.h"

class Score
{
private:
    int value;
    Text scoreText{10, 0, 3, 60, "", "fonts//Flappy-Bird.ttf"};
    std::priority_queue <int> allScores;
public:
    Score(int _value = 0) : value(_value) {}
    Score(const Score&);
    inline int getValue() const { return value; }
    inline int getHS() const { return allScores.empty() ? 0 : allScores.top(); }
    void insertScore() { allScores.push(value); }
    void updateValue() { value++; }
    void resetValue() { value = 0; }
    void draw(sf::RenderWindow&);
    Score& operator ++();
    Score operator ++(int);
    friend std::ostream& operator <<(std::ostream&, Score&);
    std::pair <int, int> getNextCoords(Pipe&, Pipe&, Pipe&);
};

#endif // SCORE_H
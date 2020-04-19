#include "Score.h"
#include <iostream>
#include <filesystem>


Score::Score(const Score& other)
{
    value = other.value;
    scoreText = other.scoreText;
}


void Score::draw(sf::RenderWindow& w)
{
    scoreText.setText(std::to_string(value));
    scoreText.draw(w);
}

Score& Score::operator ++()
{
    this->value ++;
    return *this;
}

Score Score::operator ++(int)
{
    Score aux(*this);
    ++(*this);
    return aux;
}

std::ostream& operator <<(std::ostream& out, Score& score)
{
    out << "Highscore is " << (score.allScores.empty() ? 0 : score.allScores.top()) << "\nAnd the other scores are: ";
    if(!score.allScores.empty()) score.allScores.pop();
    while(!score.allScores.empty())
    {
        out << score.allScores.top() << " ";
        score.allScores.pop();
    }
    out << "\nSee you next time, thanks for playing!\n";
    return out;
}
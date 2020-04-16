#include "Score.h"
#include <bits/stdc++.h>

Score::Score(int valuee, int positionXX, int positionYY, int thicknesss, int sizee, std::string fileNamee)
{
    value = valuee;
    positionX = positionXX;
    positionY = positionYY;
    thickness = thicknesss;
    size = sizee;
    fileName = fileNamee;
    if(fileName != "")
    {   font.loadFromFile(fileNamee);
         s.setFont(font);
    }
    s.setPosition(positionX, positionY);
    s.setOutlineThickness(thickness);
    s.setCharacterSize(size);
}


Score::Score(const Score& other)
{
    value = other.value;
    positionX = other.positionX;
    positionY = other.positionY;
    thickness = other.thickness;
    size = other.size;
    fileName = other.fileName;
    if(fileName != "")
    {   font.loadFromFile(fileName);
         s.setFont(font);
    }
    s.setPosition(positionX, positionY);
    s.setOutlineThickness(thickness);
    s.setCharacterSize(size);
}


void Score::resetValue()
{
    value = 0;
}

void Score::draw(sf::RenderWindow& w)
{
    s.setString(std::to_string(value));
    w.draw(s);
}

Score& Score::operator ++ ()
{
    this->value ++;
    return *this;
}

Score Score::operator ++ (int)
{
    Score aux(*this);
    operator ++();
    return aux;
}

void Score::insertScore()
{
    allScores.push(value);
}

void Score::print()
{
    while (!allScores.empty())
        {
            std::cout << allScores.top() << '\n';
            allScores.pop();
        }
}
#include "Score.h"
#include <iostream>
#include <filesystem>

Score::Score(int valuee, int positionXX, int positionYY, int thicknesss, int sizee, std::string fileNamee)
{
    value = valuee;
    positionX = positionXX;
    positionY = positionYY;
    thickness = thicknesss;
    size = sizee;
    fileName = fileNamee;
    try {
        if (std::filesystem::exists(fileName)) throw fileName;
        else throw 0;
    }
    catch (std::string fisier)
    {
        font.loadFromFile(fisier);
        s.setFont(font);
    }
    catch (bool nope) {
        std::cout << "Nu am putut gasi fisierul " << fileName << '\n';
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
    try {
        if (std::filesystem::exists(fileName)) throw fileName;
        else throw 0;
    }
    catch (std::string fisier)
    {
        font.loadFromFile(fisier);
        s.setFont(font);
    }
    catch (bool nope) {
        std::cout << "Nu am putut gasi fisierul " << fileName << '\n';
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
    ++(*this);
    return aux;
}

void Score::insertScore()
{
    allScores.push(value);
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
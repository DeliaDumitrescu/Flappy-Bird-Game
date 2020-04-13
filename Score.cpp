#include "Score.h"
#include <bits/stdc++.h>


Score::Score()
{
    font.loadFromFile("Flappy-Bird.ttf");
    s.setFont(font);
    value = 0;
    s.setPosition(10, 0);
    s.setOutlineThickness(3);
    s.setCharacterSize(60);
    s.setString(std::to_string(value));
}

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

class Bird{

private:
    sf::Texture t;
    sf::Sprite s;
    bool alive;
    float x, y, dy;
    int score, angle;

public:
    Bird();
    sf::Sprite get_sprite() const {return s;};
    void jump();
    void fall();
    void draw(sf::RenderWindow&);
    void reset();
};



#endif // BIRD_H

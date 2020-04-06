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
    float dy;
    int score;
    float x, y;
    int angle;
public:
    Bird();
    sf::Sprite get_sprite() const {return s;};
    void fall();
    void draw(sf::RenderWindow&);
    void reset();
    void jump();

};



#endif // BIRD_H

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>

class Bird{
private:
    sf::Texture t;
    sf::Sprite s;
public:
    Bird();
    sf::Sprite get_sprite(){return s;};

};



#endif // BIRD_H
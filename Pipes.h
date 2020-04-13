#ifndef PIPES_H
#define PIPES_H

#include <SFML/Graphics.hpp>

class Pipe
{
    int x, y;
    static int reset_x;
    sf::Texture t_up, t_down;
    sf::Sprite s_up, s_down;

public:
    Pipe();
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }
    void draw(sf::RenderWindow&);
    void move() { x--; }
    void reset();
};

#endif //PIPES_H


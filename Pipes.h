#ifndef PIPES_H
#define PIPES_H

#include <SFML/Graphics.hpp>
#include "Objects.h"
#include "Exceptions.h"

class Pipe : public Object
{
private:
    static float reset_x;
    sf::Texture t_up, t_down;
    sf::Sprite s_up, s_down;
    std::string file_up, file_down;
public:
    Pipe(float _x = 600, std::string _file_up = "images//Pipe_up.png", std::string _file_down = "images//Pipe_down.png");
    Pipe(const Pipe&);
    void setX(float val) { x = val; }
    void setY(float val) { y = val; }
    void move() { x--; }
    void reset();
    void draw(sf::RenderWindow&) override;
    void updatePosition();
    bool passed() { return x == 5; }
    Pipe& operator =(const Pipe&);
    Pipe& operator =(Pipe&&);
    Pipe operator +(float) const;
    Pipe operator -(float) const;
    void operator +=(float);
    void operator -=(float);
    void manageExceptions() override;
};

#endif //PIPES_H


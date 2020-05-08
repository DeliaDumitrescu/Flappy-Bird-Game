#ifndef PIPES_H
#define PIPES_H

#include <SFML/Graphics.hpp>
#include "Objects.h"

class Pipe : public Object
{
private:
    static int reset_x;
    sf::Texture t_up, t_down;
    sf::Sprite s_up, s_down;
    std::string file_up, file_down;
public:
    Pipe(int val_x = 600, std::string val_file_up = "images//Pipe_up.png", std::string val_file_down = "images//Pipe_down.png");
    Pipe(const Pipe&);
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }
    void move() { x--; }
    void reset();
    void draw(sf::RenderWindow&) override;
    Pipe& operator =(const Pipe&);
    Pipe operator +(int) const;
    Pipe operator -(int) const;
    void operator +=(int);
    void operator -=(int);
    void manageExceptions();
};

#endif //PIPES_H


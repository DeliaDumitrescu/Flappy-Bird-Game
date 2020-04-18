#ifndef PIPES_H
#define PIPES_H

#include <SFML/Graphics.hpp>

class Pipe
{
private:
    int x, y;
    static int reset_x;
    sf::Texture t_up, t_down;
    sf::Sprite s_up, s_down;
    std::string file_up, file_down;

public:

    Pipe(int val_x = 0, std::string val_file_up = "", std::string val_file_down = "");
    Pipe(const Pipe&);
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int val) { x = val; }
    void setY(int val) { y = val; }
    void draw(sf::RenderWindow&);
    void move() { x--; }
    void reset();
    Pipe& operator = (const Pipe&);
    Pipe operator + (int) const;
    Pipe operator - (int) const;
    void operator += (int);

};

#endif //PIPES_H


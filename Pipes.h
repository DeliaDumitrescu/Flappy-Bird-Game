#ifndef PIPES_H
#define PIPES_H

#include <SFML/Graphics.hpp>

class Pipe
{
	int x = 600;
	int y = rand() % 400 + 350;
	sf::Texture t_up, t_down;
	sf::Sprite s_up, s_down;
public:
	Pipe();
	int getX() { return x; }
	void setX(int val) { x = val; }
	void draw(sf::RenderWindow&);
	void move() { x--; }
};

#endif PIPES_H
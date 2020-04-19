#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>

class Object
{
protected:
	float x, y;
public:
	float getX() const { return x; }
	float getY() const { return y; }
	virtual void draw(sf::RenderWindow&) = 0;
};

#endif
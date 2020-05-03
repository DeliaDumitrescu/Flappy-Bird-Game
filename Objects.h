#ifndef OBJECTS_H
#define OBJECTS_H

#include <SFML/Graphics.hpp>

class Object
{
protected:
	float x, y;
public:
	inline float getX() const { return x; }
	inline float getY() const { return y; }
	virtual void draw(sf::RenderWindow&) = 0;
    virtual void manageExceptions() = 0;
    virtual ~Object(){}
};

#endif
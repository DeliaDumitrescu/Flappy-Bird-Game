#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipes.h"
#include "Score.h"

class Collision
{
	Bird &bird;
	Pipe &first, &second, &third;
	Score &score;
	int first_pipe_x, first_pipe_y;
public:
	Collision(Bird &b, Pipe &p1, Pipe &p2, Pipe &p3, Score &s) : bird(b), first(p1), second(p2), third(p3), score(s) {}
	void isCollide();
	void update();
};

#endif
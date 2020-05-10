#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <filesystem>
#include "Bird.h"
#include "Pipes.h"
#include "Score.h"

//Facade
class Collision
{
private:
	Bird &bird;
	Pipe &first, &second, &third;
	Score &score;
	sf::SoundBuffer buffer;
	sf::Sound coin_sound;

public:
	Collision(Bird &b, Pipe &p1, Pipe &p2, Pipe &p3, Score &s);
	void isCollide();
	void update();
};

#endif
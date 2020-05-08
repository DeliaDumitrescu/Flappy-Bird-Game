#ifndef COLLISION_H
#define COLLISION_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	Collision(Bird &b, Pipe &p1, Pipe &p2, Pipe &p3, Score &s) : bird(b), first(p1), second(p2), third(p3), score(s) {
		buffer.loadFromFile("sounds//coin.wav");
		coin_sound.setBuffer(buffer);
	}
	void isCollide();
	void update();
};

#endif
#include "Collision.h"

Collision::Collision(Bird &b, Pipe &p1, Pipe &p2, Pipe &p3, Score &s): bird(b), first(p1), second(p2), third(p3), score(s)
{
	buffer.loadFromFile("sounds//coin.wav");
	coin_sound.setBuffer(buffer);
}


void Collision::isCollide()
{
	std::pair <float, float> coords = score.getNextCoords(first, second, third);

	if(bird.hitsPipe(coords.first, coords.second) && bird.isAlive())
	{
		score.insertScore();
		bird.die();
	}
}

void Collision::update()
{
	for (auto pipe : { &first, &second, &third }) {
		pipe->updatePosition();
		if (pipe->passed() && bird.isAlive()) score++, coin_sound.play();
	}
}
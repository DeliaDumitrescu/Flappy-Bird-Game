#include "Collision.h"

void Collision::isCollide()
{
	std::pair <int, int> coords = score.getNextCoords(first, second, third);

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
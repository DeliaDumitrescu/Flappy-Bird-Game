#include "Collision.h"

void Collision::isCollide()
{
	Pipe currentPipe = score.getCurrentPipe(first, second, third);
	float x = currentPipe.getX();
	float y = currentPipe.getY();

	if(bird.hitsPipe(x, y) && bird.isAlive())
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
#include "Collision.h"

void Collision::isCollide()
{
	if (score.getValue() % 3 == 0) {
		first_pipe_x = first.getX();
		first_pipe_y = first.getY();
	}
	else if (score.getValue() % 3 == 1) {
		first_pipe_x = second.getX();
		first_pipe_y = second.getY();
	}
	else {
		first_pipe_x = third.getX();
		first_pipe_y = third.getY();
	}
	if (bird.getX() + 30 > first_pipe_x && (bird.getY() - 22 < 800 - first_pipe_y || bird.getY() + 22 > 1000 - first_pipe_y)) bird.die();
}

void Collision::update()
{
	for (auto i : { &first, &second, &third }) {
		if (i->getX() < -150) i->setX(1350), i->setY(rand() % 400 + 350);
		if (i->getX() == 5 && bird.isAlive()) score.updateValue(), coin_sound.play();
	}
}
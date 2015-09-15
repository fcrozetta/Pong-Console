#include "stdafx.h"

void dotHitWall(char Screen[HEIGHT][WIDTH], Dot *d) {
	switch (d->direction)
	{
	case direction::UP:
		d->direction = DOWN;
		break;
	case direction::DOWN:
		d->direction = UP;
		break;
	case direction::LEFT:
		d->direction = RIGHT;
		break;
	case direction::RIGHT:
		d->direction = LEFT;
		break;
	case direction::UPLEFT:
		d->direction = DOWNLEFT;
		break;
	case direction::UPRIGHT:
		d->direction = DOWNRIGHT;
		break;
	case direction::DOWNLEFT:
		d->direction = UPLEFT;
		break;
	case direction::DOWNRIGHT:
		d->direction = UPRIGHT;
		break;
	default:
		d->direction = LEFT;
		break;
	};
}

void initializeDot(char screen[HEIGHT][WIDTH], Dot *d,Direction direction) {
	d->direction = direction;
	d->deltaHeight = 1;
	d->deltaWidth = 1;
	d->height = HEIGHT / 2;
	d->width = WIDTH / 2;
}

void moveDot(char screen[HEIGHT][WIDTH], Direction dotDirection, Dot * d) {
	screen[d->height][d->width] = SPACE;
	bool hitWall = false;
	switch (dotDirection)
	{
	case direction::UP:
		d->height -= d->deltaHeight;
		break;
	case direction::DOWN:
		d->height += d->deltaHeight;
		break;
	case direction::RIGHT:
		d->width += d->deltaWidth;
		break;
	case direction::LEFT:
		d->width -= d->deltaWidth;
		break;
	case direction::UPLEFT:
		moveDot(screen, UP, d);
		moveDot(screen, LEFT, d);
		break;
	case direction::UPRIGHT:
		moveDot(screen, UP, d);
		moveDot(screen, RIGHT, d);
		break;
	case direction::DOWNLEFT:
		moveDot(screen, DOWN, d);
		moveDot(screen, LEFT, d);
		break;
	case direction::DOWNRIGHT:
		moveDot(screen, DOWN, d);
		moveDot(screen, RIGHT, d);
		break;
	}

	/* Bounding Box */
	if (d->height <= 0)
	{
		d->height = 1;
		hitWall = true;
	}
	if (d->height >= HEIGHT-1)
	{
		d->height = HEIGHT - 2;
		hitWall = true;
	}
	if (d->width < 0)
	{
		initializeDot(screen, d, direction::UPLEFT);
	}
	if (d->width >= WIDTH)
	{
		initializeDot(screen, d, direction::UPRIGHT);
	}

	if (hitWall)
	{
		dotHitWall(screen, d);
	}
	screen[d->height][d->width] = DOT;
}
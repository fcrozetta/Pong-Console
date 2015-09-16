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
	if (screen[d->height][d->width] == RACKET_BRUSH)
	{
		screen[d->height][d->width] = RACKET_BRUSH;
		return;
	}
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

void dotHitRacket(char screen[HEIGHT][WIDTH], Dot *d,Racket *r) {
	/*

	[+3] | -> UPRIGHT	(deltaHeight +=3 && deltaWidth = 2)	UPLEFT	 <- |
	[+2] | -> UPRIGHT	(deltaHeight +=2 && deltaWidth = 1)	UPLEFT	 <- |
	[+1] | -> UPRIGHT	(deltaHeight +=1 && deltaWidth = 1)	UPLEFT	 <- |
	[0]  | -> RIGHT		(deltaHeight = 0 && deltaWidth = 1)	LEFT	 <- |
	[-1] | -> DOWNRIGHT	(deltaHeight +=1 && deltaWidth = 1)	DOWNLEFT <- |
	[-2] | -> DOWNRIGHT	(deltaHeight +=2 && deltaWidth = 1)	DOWNLEFT <- |
	[-3] | -> DOWNRIGHT	(deltaHeight +=3 && deltaWidth = 2)	DOWNLEFT <- |

	*/
	int hitPosition = r->centerH - d->height;
	Direction dir;
	r->side == Side::LEFT_SIDE ? d->width += 1 : d->width -= 1;
	switch (hitPosition)
	{
	case 0:
		d->deltaHeight = 0;
		d->deltaWidth = 1;
		r->side == Side::LEFT_SIDE ? d->direction=RIGHT : d->direction=LEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, RIGHT, d) : moveDot(screen, LEFT, d);
		break;
	case 1:
		d->deltaHeight += 1;
		d->deltaWidth = 1;
		r->side == Side::LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, UPRIGHT, d) : moveDot(screen, UPLEFT, d);
		break;
	case 2:
		d->deltaHeight += 2;
		d->deltaWidth = 1;
		r->side == Side::LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, UPRIGHT, d) : moveDot(screen, UPLEFT, d);
		break;
	case 3:
		d->deltaHeight += 3;
		d->deltaWidth = 2;
		r->side == Side::LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, UPRIGHT, d) : moveDot(screen, UPLEFT, d);
		break;
	case -1:
		d->deltaHeight += 1;
		d->deltaWidth = 1;
		r->side == Side::LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d) : moveDot(screen, DOWNLEFT, d);
		break;
	case -2:
		d->deltaHeight += 2;
		d->deltaWidth = 1;
		r->side == Side::LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d) : moveDot(screen, DOWNLEFT, d);
		break;
	case -3:
		d->deltaHeight += 3;
		d->deltaWidth = 2;
		r->side == Side::LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == Side::LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d) : moveDot(screen, DOWNLEFT, d);
		break;
	}
}
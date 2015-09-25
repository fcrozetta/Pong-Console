#include "stdafx.h"

void gameScore(Racket *r){
	r->score++;
}

void initializeDot(Dot *d,Direction direction) {
	/* initialize Dot, using new coordinates :) */
	d->direction = direction;
	d->deltaY = 1;
	d->deltaX = 1;
	d->posXY.Y = HEIGHT / 2;
	d->posXY.X = WIDTH / 2;

	drawDot(d);
}

void drawDot(Dot *d) {
	/* this SHOULD print the Dot */
	draw(d->posXY, DOT);
}

void nextPos(Dot *d,Direction dir) {
	/* Set The next position, to know what will be there, before hit */
	switch (dir)
	{
	case UP:
		d->nextPos.Y -= d->deltaY;
		break;
	case DOWN:
		d->nextPos.Y += d->deltaY;
		break;
	case LEFT:
		d->nextPos.X -= d->deltaX;
		break;
	case RIGHT:
		d->nextPos.X += d->deltaX;
		break;
	case UPLEFT:
		nextPos(d, UP);
		nextPos(d, LEFT);
		break;
	case DOWNLEFT:
		nextPos(d, DOWN);
		nextPos(d, LEFT);
		break;
	case UPRIGHT:
		nextPos(d, UP);
		nextPos(d, RIGHT);
		break;
	case DOWNRIGHT:
		nextPos(d, DOWN);
		nextPos(d, RIGHT);
		break;
	}
}

void moveDot(Dot * d) {
	d->posXY = d->nextPos;
}

void dotHitRacket(Dot *d, Racket *r, Racket **  list) {
	/*

	[+3] | -> UPRIGHT	(deltaHeight +=3 && deltaWidth = 2)	UPLEFT	 <- |
	[+2] | -> UPRIGHT	(deltaHeight +=2 && deltaWidth = 1)	UPLEFT	 <- |
	[+1] | -> UPRIGHT	(deltaHeight +=1 && deltaWidth = 1)	UPLEFT	 <- |
	[0]  | -> RIGHT		(deltaHeight = 0 && deltaWidth = 1)	LEFT	 <- |
	[-1] | -> DOWNRIGHT	(deltaHeight +=1 && deltaWidth = 1)	DOWNLEFT <- |
	[-2] | -> DOWNRIGHT	(deltaHeight +=2 && deltaWidth = 1)	DOWNLEFT <- |
	[-3] | -> DOWNRIGHT	(deltaHeight +=3 && deltaWidth = 2)	DOWNLEFT <- |

	*/

}
void dotHitWall(Dot *d) {
	switch (d->direction)
	{
	case UP:
		d->direction = DOWN;
		break;
	case DOWN:
		d->direction = UP;
		break;
	case LEFT:
		d->direction = RIGHT;
		break;
	case RIGHT:
		d->direction = LEFT;
		break;
	case UPLEFT:
		d->direction = DOWNLEFT;
		break;
	case UPRIGHT:
		d->direction = DOWNRIGHT;
		break;
	case DOWNLEFT:
		d->direction = UPLEFT;
		break;
	case DOWNRIGHT:
		d->direction = UPRIGHT;
		break;
	default:
		d->direction = LEFT;
		break;
	};
}
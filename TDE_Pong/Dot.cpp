#include "stdafx.h"

void gameScore(int side,Racket ** list){
	Racket *r1=list[0], *r2=list[1];
	switch(side){
		case UPLEFT:
			r1->score += 1;
		break;
		case UPRIGHT:
			r2->score += 1;
		break;
	}
}

void dotHitWall(char Screen[HEIGHT][WIDTH], Dot *d) {
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

void initializeDot(char screen[HEIGHT][WIDTH], Dot *d,Direction direction) {
	d->direction = direction;
	d->deltaHeight = 1;
	d->deltaWidth = 1;
	d->height = HEIGHT / 2;
	d->width = WIDTH / 2;
}

void moveDot(char screen[HEIGHT][WIDTH], Direction dotDirection, Dot * d,Racket ** list) {
	if (screen[d->height][d->width] == RACKET_BRUSH)
	{
		screen[d->height][d->width] = RACKET_BRUSH;
		return;
	}
	screen[d->height][d->width] = SPACE;
	bool hitWall = false;
	switch (dotDirection)
	{
	case UP:
		d->height -= d->deltaHeight;
		break;
	case DOWN:
		d->height += d->deltaHeight;
		break;
	case RIGHT:
		d->width += d->deltaWidth;
		break;
	case LEFT:
		d->width -= d->deltaWidth;
		break;
	case UPLEFT:
		moveDot(screen, UP, d, list);
		moveDot(screen, LEFT, d,list);
		break;
	case UPRIGHT:
		moveDot(screen, UP, d, list);
		moveDot(screen, RIGHT, d, list);
		break;
	case DOWNLEFT:
		moveDot(screen, DOWN, d, list);
		moveDot(screen, LEFT, d, list);
		break;
	case DOWNRIGHT:
		moveDot(screen, DOWN, d, list);
		moveDot(screen, RIGHT, d, list);
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
		initializeDot(screen, d, UPLEFT);
		gameScore(UPLEFT, list);
	}
	if (d->width >= WIDTH)
	{
		initializeDot(screen, d, UPRIGHT);
		gameScore(UPLEFT, list);
	}

	if (hitWall)
	{
		dotHitWall(screen, d);
	}
	screen[d->height][d->width] = DOT;
}

void dotHitRacket(char screen[HEIGHT][WIDTH], Dot *d, Racket *r, Racket **  list) {
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
	r->side == LEFT_SIDE ? d->width += 1 : d->width -= 1;
	switch (hitPosition)
	{
	case 0:
		d->deltaHeight = 0;
		d->deltaWidth = 1;
		r->side == LEFT_SIDE ? d->direction=RIGHT : d->direction=LEFT;
		r->side == LEFT_SIDE ? moveDot(screen, RIGHT, d, list) : moveDot(screen, LEFT, d,list);
		break;
	case 1:
		d->deltaHeight += 1;
		d->deltaWidth = 1;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case 2:
		d->deltaHeight += 2;
		d->deltaWidth = 1;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case 3:
		d->deltaHeight += 3;
		d->deltaWidth = 2;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case -1:
		d->deltaHeight += 1;
		d->deltaWidth = 1;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	case -2:
		d->deltaHeight += 2;
		d->deltaWidth = 1;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	case -3:
		d->deltaHeight += 3;
		d->deltaWidth = 2;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	}
}

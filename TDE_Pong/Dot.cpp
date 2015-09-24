#include "stdafx.h"

void gameScore(Racket *r){
	r->score++;
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

void initializeDot(Dot *d,Direction direction) {
	/* initialize Dot, using new coordinates :) */
	d->direction = direction;
	d->deltaY = 1;
	d->deltaX = 1;
	d->posXY.Y = HEIGHT / 2;
	d->posXY.X = WIDTH / 2;
}

void drawDot(Dot *d) {
	/* this SHOULD print the Dot */
	draw(d->posXY, DOT);
}

void moveDot(Direction dotDirection, Dot * d,Racket ** list) {
	/* Change this Logic :
		1-> Print Space in old place
		2-> Check if the next position is a "hit"
			yes -> return 1 position, draw and calculate direction
			no -> draw ..
		*/


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
		d->height -= d->deltaY;
		break;
	case DOWN:
		d->height += d->deltaY;
		break;
	case RIGHT:
		d->width += d->deltaX;
		break;
	case LEFT:
		d->width -= d->deltaX;
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
		gameScore(list[1]);
		printf("Player 1: %d\t\tPlayer 2: %d", list[0]->score, list[1]->score);
		_getch();
		initializeDot(screen, d, UPLEFT);
		
	}
	if (d->width >= WIDTH)
	{
		gameScore(list[2]);
		printf("Player 1: %d\t\tPlayer 2: %d", list[0]->score, list[1]->score);
		_getch();
		initializeDot(screen, d, UPRIGHT);
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
	//int hitPosition = r->centerH - d->height;
	int hitPosition = 0;
	Direction dir;
	r->side == LEFT_SIDE ? d->width += 1 : d->width -= 1;
	switch (hitPosition)
	{
	case 0:
		d->deltaY = 0;
		d->deltaX = 1;
		r->side == LEFT_SIDE ? d->direction=RIGHT : d->direction=LEFT;
		r->side == LEFT_SIDE ? moveDot(screen, RIGHT, d, list) : moveDot(screen, LEFT, d,list);
		break;
	case 1:
		d->deltaY += 1;
		d->deltaX = 1;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case 2:
		d->deltaY += 2;
		d->deltaX = 1;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case 3:
		d->deltaY += 3;
		d->deltaX = 2;
		r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, UPRIGHT, d, list) : moveDot(screen, UPLEFT, d, list);
		break;
	case -1:
		d->deltaY += 1;
		d->deltaX = 1;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	case -2:
		d->deltaY += 2;
		d->deltaX = 1;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	case -3:
		d->deltaY += 3;
		d->deltaX = 2;
		r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
		r->side == LEFT_SIDE ? moveDot(screen, DOWNRIGHT, d, list) : moveDot(screen, DOWNLEFT, d, list);
		break;
	}
}

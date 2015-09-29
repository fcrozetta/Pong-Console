#include "stdafx.h"



void initializeDot(Dot *d,Direction direction) {
	/* initialize Dot, using new coordinates :) */
	d->direction = direction;
	d->deltaY = 1;
	d->deltaX = 1;
	d->leftChar = SPACE;
	d->rightChar = SPACE;
	d->nextPosChar = SPACE;
	d->posXY.Y = HEIGHT / 2;
	d->posXY.X = WIDTH / 2;
	d->nextPos = { 0,0 };

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

void moveDot(Dot * d,direction dir,Racket **rList) {
	/* Calc based on NextPosition. This avoid printing over other things*/
	if ((d->leftChar == GOAL) || (d->rightChar == GOAL)) 
	{
		// Score!
		d->leftChar == GOAL ? ((rList[1]->score++) && (d->direction = UPLEFT)) : ((rList[0]->score++) && (d->direction = UPRIGHT));
		draw(d->posXY, SPACE);
		printScore(rList[0], rList[1]);
		initializeDot(d, d->direction);
		_getch();
	} 
	else if ( 
		((d->leftChar == RACKET_BRUSH) && ((d->direction == LEFT) || (d->direction == UPLEFT) || ((d->direction == DOWNLEFT))))
		|| ((d->rightChar == RACKET_BRUSH) && ((d->direction == RIGHT) || (d->direction == UPRIGHT) || ((d->direction == DOWNRIGHT))))
		|| (d->nextPosChar == RACKET_BRUSH))
	{
		// Racket
		d->nextPos.X < WIDTH / 2 ? dotHitRacket(d, rList[0]) : dotHitRacket(d, rList[1]);
		draw(d->posXY, SPACE);
		d->posXY = d->nextPos;
	}
	else if (d->nextPosChar == WALL) {
		// Wall
		if (d->nextPos.Y <= 0)
		{
			// Above Top
			d->nextPos.Y = 1;
			d->nextPos.X = d->posXY.X;
			draw(d->posXY, SPACE);
			d->posXY = d->nextPos;
			drawDot(d);
		}
		if (d->nextPos.Y >= HEIGHT)
		{
			//Below bottom
			d->posXY.Y = HEIGHT - 1;
			draw(d->posXY, SPACE);
			d->posXY = d->nextPos;
			drawDot(d);
		}
		dotHitWall(d);
	}
	else {
		// Space
		if (d->nextPos.Y <= 0)
		{
			// Above Top
			d->nextPos.Y == 1;
			draw(d->posXY, SPACE);
			d->posXY = d->nextPos;
			drawDot(d);
			dotHitWall(d);
		}
		if (d->nextPos.Y >= HEIGHT)
		{
			//Below bottom
			d->posXY.Y == HEIGHT - 2;
			draw(d->posXY, SPACE);
			d->posXY = d->nextPos;
			drawDot(d);
			dotHitWall(d);
		}
		draw(d->posXY, SPACE);
		d->posXY = d->nextPos;
	}

}

void dotHitRacket(Dot *d, Racket *r) {
	/*

	[+3] | -> UPRIGHT	(deltaHeight +=3 && deltaWidth = 2)	UPLEFT	 <- |
	[+2] | -> UPRIGHT	(deltaHeight +=2 && deltaWidth = 1)	UPLEFT	 <- |
	[+1] | -> UPRIGHT	(deltaHeight +=1 && deltaWidth = 1)	UPLEFT	 <- |
	[0]  | -> RIGHT		(deltaHeight = 0 && deltaWidth = 1)	LEFT	 <- |
	[-1] | -> DOWNRIGHT	(deltaHeight +=1 && deltaWidth = 1)	DOWNLEFT <- |
	[-2] | -> DOWNRIGHT	(deltaHeight +=2 && deltaWidth = 1)	DOWNLEFT <- |
	[-3] | -> DOWNRIGHT	(deltaHeight +=3 && deltaWidth = 2)	DOWNLEFT <- |

	*/
	int hitPosition;
	
	if ((d->leftChar == RACKET_BRUSH) || (d->rightChar == RACKET_BRUSH))
	{
		
		d->leftChar = SPACE;
		d->rightChar = SPACE;
		hitPosition = r->centerXY.Y - d->nextPos.Y; // Set the difference between center of racket and dot (from -3 to +3)
		Direction dir;
		switch (hitPosition)
		{
		case 0:
			d->deltaY = 0;
			d->deltaX = 1;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = RIGHT : d->direction = LEFT;
			nextPos(d, d->direction);
			break;
		case 1:
			d->deltaY += 1;
			d->deltaX = 1;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
			nextPos(d, d->direction);
			break;
		case 2:
			d->deltaY += 2;
			d->deltaX = 1;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
			nextPos(d, d->direction);
			break;
		case 3:
			d->deltaY += 3;
			d->deltaX = 2;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = UPRIGHT : d->direction = UPLEFT;
			nextPos(d, d->direction);
			break;
		case -1:
			d->deltaY += 1;
			d->deltaX = 1;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
			nextPos(d, d->direction);
			break;
		case -2:
			d->deltaY += 2;
			d->deltaX = 1;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
			nextPos(d, d->direction);
			break;
		case -3:
			d->deltaY += 3;
			d->deltaX = 2;
			d->nextPos = d->posXY;
			r->side == LEFT_SIDE ? d->direction = DOWNRIGHT : d->direction = DOWNLEFT;
			nextPos(d, d->direction);
			break;
		}
	}
	else
	{
		r->side == LEFT_SIDE ? ((d->nextPos.X++) && (d->leftChar = RACKET_BRUSH)) : ((d->nextPos.X--) && (d->rightChar = RACKET_BRUSH));
		draw(d->posXY, SPACE);
		dotHitRacket(d, r);
	}
	
	
}

void dotHitWall(Dot *d){
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
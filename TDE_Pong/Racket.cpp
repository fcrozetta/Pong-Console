#include "stdafx.h"

void initializeRacket(char screen[HEIGHT][WIDTH], racket *r, Side s) {
	r->centerH = HEIGHT / 2;
	r->side = s;
	switch (s)
	{
	case Side::LEFT_SIDE:
		
		r->centerW = 1;
		break;
	case Side::RIGHT_SIDE:
		r->centerW = WIDTH - 2;
	}
}

void drawRacket(char screen[HEIGHT][WIDTH], racket *r) {
	for (int i = 0; i < r->size; i++)
	{
		screen[r->centerH - r->size / 2 + i][r->centerW] = RACKET_BRUSH;
	}
}

void moveRacket(char screen[HEIGHT][WIDTH], Racket *r, Direction d) {
	/* It's working. do NOT touch */
	switch (d)
	{
	case Direction::UP:
		r->centerH -= r->speed;
		break;
	case Direction::DOWN:
		r->centerH += r->speed;
	}

	if (r->centerH - (r->size /2) <= 0) // Top limit
	{
		r->centerH = (r->size / 2) + 1;
	}

	if (r->centerH + (r->size/2) >= HEIGHT-1) //Bottom limit
	{
		r->centerH = HEIGHT - (r->size/2) -2;
	}
}
void moveCPU(char screen[HEIGHT][WIDTH], Racket *r,Direction d) {
	
	switch (r->directionCPU)
	{
	case Direction::UP:
		r->centerH -= r->speed;
		break;
	case Direction::DOWN:
		r->centerH += r->speed;
	}	
	// Case the option selected is 2 ( or expert )
	if (r->difficulty) {
		switch (d)
		{
		case UP:
			r->directionCPU = UP;
			break;
		case DOWN:
			r->directionCPU = DOWN;
			break;
		case RIGHT:
			r->directionCPU = DOWN;
			break;
		case UPLEFT:
			r->directionCPU = UP;
			break;
		case UPRIGHT:
			r->directionCPU = UP;
			break;
		case DOWNLEFT:
			r->directionCPU = DOWN;
			break;
		case DOWNRIGHT:
			r->directionCPU = DOWN;
			break;
		}
	}
	if (r->centerH - (r->size / 2) <= 0) // Top limit
	{
		r->centerH = (r->size / 2) + 1;
		// Case the option selected is 1 ( or easy )
		if (!r->difficulty) { r->directionCPU = DOWN; }
	}

	if (r->centerH + (r->size / 2) >= HEIGHT - 1) //Bottom limit
	{
		r->centerH = HEIGHT - (r->size / 2) - 2;
		// Case the option selected is 1 ( or easy )
		if (!r->difficulty) { r->directionCPU = UP; }
	}

}

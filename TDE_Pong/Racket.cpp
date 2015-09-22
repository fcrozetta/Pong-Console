#include "stdafx.h"

void moveRacket(char screen[HEIGHT][WIDTH], Racket *r) {

}

void initializeRacket(racket *r, Side s) {
	switch (s)
	{
	case Side::LEFT_SIDE:
		r->centerXY = { 2,HEIGHT / 2 };
		break;
	case Side::RIGHT_SIDE:
		r->centerXY = { WIDTH - 2,HEIGHT / 2 };
		break;
	}
	r->side = s;

	drawRacket(r);
	
}

void drawRacket(racket *r) {
	for (int i = 0; i < r->size; i++)
	{
		short y = r->centerXY.Y;
		short x = (r->centerXY.X / 2) + 1;
		printf("%d", x);
		draw({ x,y }, RACKET_BRUSH);
	}
}

void moveRacket(char screen[HEIGHT][WIDTH], Racket *r, Direction d) {
	for (int i = 0; i < r->size; i++)
	{
		screen[r->centerH - r->size / 2 + i][r->centerW] = SPACE;
		
	}
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

	for (int i = 0; i < r->size; i++)
	{
		screen[r->centerH - r->size / 2 + i][r->centerW] = RACKET_BRUSH;
	}
}
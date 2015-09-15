#include "stdafx.h"

void moveRacket(char screen[HEIGHT][WIDTH], Racket *r) {

}

void initializeRacket(char screen[HEIGHT][WIDTH], racket *r, Side s) {
	r->centerH = HEIGHT / 2;
	switch (s)
	{
	case Side::LEFT_SIDE:
		r->centerW = 2;
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
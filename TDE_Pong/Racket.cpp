#include "stdafx.h"

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

void clearRacket(racket *r) {
	for (int i = 0; i <= (r->size / 2); i++)
	{
		short x = r->centerXY.X;
		short y_top = (r->centerXY.Y) + i;
		short y_bottom = (r->centerXY.Y) - i;
		draw({ x,y_top }, SPACE);
		draw({ x,y_bottom }, SPACE);
	}
}


void drawRacket(racket *r) {
	clearRacket(r);
	for (int i = 0 ; i <= (r->size / 2); i++)
	{
		short x = r->centerXY.X;
		short y_top = (r->centerXY.Y) + i;
		short y_bottom = (r->centerXY.Y) - i;
		draw({ x,y_top }, RACKET_BRUSH);
		draw({ x,y_bottom }, RACKET_BRUSH);
	}
}

void moveRacket(Racket *r, Direction d) {
	/* It's still working.. Keep NOT touching this code :) */
	clearRacket(r);
	switch (d)
	{
	case Direction::UP:
		r->centerXY.Y -= r->speed;
		break;
	case Direction::DOWN:
		r->centerXY.Y += r->speed;
	}

	if (r->centerXY.Y - (r->size /2) <= 0) // Top limit
	{
		r->centerXY.Y = (r->size / 2) + 1;
	}

	if (r->centerXY.Y + (r->size/2) >= HEIGHT-1) //Bottom limit
	{
		r->centerXY.Y = HEIGHT - (r->size/2) -2;
	}

	drawRacket(r);
}
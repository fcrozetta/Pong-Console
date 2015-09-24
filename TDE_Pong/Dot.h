#pragma once
#include "stdafx.h"

typedef struct dot
{
	COORD posXY = {};
	int deltaX; // Variation for x (width)
	int deltaY; // Variation for y (height)
	Direction direction;
}Dot;

void dotHitWall(char Screen[HEIGHT][WIDTH], Dot *d);
void initializeDot(Dot * d, Direction direction);
void moveDot(Dot * d, Racket ** list);
void moveDot(char screen[HEIGHT][WIDTH], Direction dotDirection, Dot * d,Racket ** list);
void dotHitRacket(char screen[HEIGHT][WIDTH], Dot * d, Racket * r,Racket ** list);


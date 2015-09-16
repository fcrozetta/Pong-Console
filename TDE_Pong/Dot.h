#pragma once
#include "stdafx.h"

typedef struct dot
{
	int width; // Position x (width) 
	int height; // Position y (height)
	int deltaWidth; // Variation for x (width)
	int deltaHeight; // Variation for y (height)
	Direction direction;
}Dot;

void dotHitWall(char Screen[HEIGHT][WIDTH], Dot *d);
void initializeDot(char screen[HEIGHT][WIDTH], Dot * d,direction direction);
void moveDot(char screen[HEIGHT][WIDTH], Direction dotDirection, Dot * d);
void dotHitRacket(char screen[HEIGHT][WIDTH], Dot * d, Racket * r);


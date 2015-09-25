#pragma once
#include "stdafx.h"

typedef struct dot
{
	COORD posXY = {};
	COORD nextPos = {};
	char nextPosChar;
	int deltaX; // Variation for x (width)
	int deltaY; // Variation for y (height)
	Direction direction;
}Dot;

void initializeDot(Dot * d, Direction direction);

void drawDot(Dot * d);

void nextPos(Dot * d, Direction dir);

void moveDot(Dot * d);

void dotHitRacket(Dot * d, Racket * r, Racket ** list);

void dotHitWall(Dot * d);

void moveDot(Dot *d,direction dir);
#pragma once
#include "stdafx.h"

typedef struct racket
{
	COORD centerXY = {}; //X,Y coodinates
	short speed = 1; // movement speed
	short size = 7; //size of racket
	int score = 0; // Score... obbviously
	Side side; //Left or right
}Racket;

void initializeRacket(racket * r, Side s);

void clearRacket(racket * r);

void drawRacket(racket * r);

void moveRacket(Racket * r, Direction d);

void printScore(Racket * r1, Racket * r2);

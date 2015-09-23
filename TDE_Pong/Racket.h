#pragma once
#include "stdafx.h"

typedef struct racket
{
	COORD centerXY = {};
	int speed = 1; // movement speed
	int score = 0;
	int size = 7; //size of racket
	Side side; //Left or right
}Racket;

void initializeRacket(racket * r, Side s);

void drawRacket(racket * r);

void moveRacket(Racket * r, Direction d);

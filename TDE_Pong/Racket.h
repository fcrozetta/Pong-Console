#pragma once
#include "stdafx.h"

typedef struct racket
{
	int centerH; // height postion (y)
	int centerW; // width position (x)
	int speed = 1; // movement speed
	int score = 0;
	int size = 7; //size of racket
	Side side; //Left or right
}Racket;

void initializeRacket(char screen[HEIGHT][WIDTH], racket * r, Side s);

void drawRacket(char screen[HEIGHT][WIDTH], racket * r);

void moveRacket(char screen[HEIGHT][WIDTH], Racket * r, Direction d);

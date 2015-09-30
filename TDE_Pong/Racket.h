#pragma once
#include "stdafx.h"

typedef struct racket
{
	int centerH; // height postion (y)
	int centerW; // width position (x)
	int speed = 1; // movement speed
	int score = 0; //score
	int size = 7; //size of racket
	boolean isplayer; //is controled by player
	Direction directionCPU = UP;// up/down racket cpu
	boolean difficulty = false;// Difficulty CPU
	Side side; //Left or right
}Racket;

void initializeRacket(char screen[HEIGHT][WIDTH], racket * r, Side s);

void drawRacket(char screen[HEIGHT][WIDTH], racket * r);

void moveRacket(char screen[HEIGHT][WIDTH], Racket * r, Direction d);

void moveCPU(char screen[HEIGHT][WIDTH], Racket * r, Direction d);
void moveCPU(char screen[HEIGHT][WIDTH], Racket * r, Direction d, int positionx);


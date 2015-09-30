#pragma once
#include "stdafx.h"

typedef enum side
{
	LEFT_SIDE,
	RIGHT_SIDE
}Side;

typedef enum direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	UPLEFT,
	UPRIGHT,
	DOWNLEFT,
	DOWNRIGHT
}Direction;


void initialize(char screen[HEIGHT][WIDTH]);
void draw(char screen[HEIGHT][WIDTH]);
bool gameMenu(boolean * d);
void printScore(int p1, int p2);
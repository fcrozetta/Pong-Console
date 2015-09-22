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


void drawScreen();

void draw(COORD posXY, char symbol);

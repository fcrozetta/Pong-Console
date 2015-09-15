#pragma once
#include "stdafx.h"

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
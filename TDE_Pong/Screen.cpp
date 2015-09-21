#pragma once
#include "stdafx.h"

void initialize(char screen[HEIGHT][WIDTH]) {
	int i, j;

	/* Creates walls on top and bottom */
	for ( i = 0; i < HEIGHT; i +=(HEIGHT-1))
	{
		for ( j = 0;  j < WIDTH;  j++)
		{
			screen[i][j] = WALL_TOP_BOTTOM;
		}
	}

	/* Creates walls on left and right sides */
	for ( i = 1; i < HEIGHT-1; i++)
	{
		for (j = 0; j < WIDTH; j += (WIDTH-1))
		{
			screen[i][j] = WALL_LEFT_RIGHT;
		}
	}

	/* Creates Empty spaces in the middle */
	for (i = 1; i < HEIGHT-1; i++)
	{
		for (j = 1; j < WIDTH-1; j++)
		{
			screen[i][j] = SPACE;
		}
	}
}

void draw(char screen[HEIGHT][WIDTH]) {
	/* Draw the screen */
	clear();
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			printf("%c", screen[i][j]);
		}
		printf("\n");
	}
}

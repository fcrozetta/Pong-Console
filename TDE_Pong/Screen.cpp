#pragma once
#include "stdafx.h"

void drawScreen() {
	/* Draw the screen */
	for (short i = 1; i < HEIGHT; i++) //Draw Left && Right
	{
		draw({ 0,i }, GOAL);
		draw({ WIDTH,i }, GOAL);
	}

	for (short i = 0; i < WIDTH; i++) //Draw Top && Bottom
	{
		draw({ i,0 }, WALL);
		draw({ i,HEIGHT }, WALL);
	}

}

void draw(COORD posXY,char symbol) {
	/* Draw the something */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
	printf("%c", symbol);

}


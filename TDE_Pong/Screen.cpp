#pragma once
#include "stdafx.h"

void drawScreen() {
	for (short i = 0; i < HEIGHT; i++) //Draw Top && Bottom
	{
		draw({ 0,i }, WALL_TOP_BOTTOM);
		draw({ WIDTH-1,i }, WALL_TOP_BOTTOM);
	}

	for (short i = 1; i < WIDTH; i++) //Draw Left && Right
	{
		draw({ i,0 }, WALL_LEFT_RIGHT);
		draw({ i,HEIGHT-1 }, WALL_LEFT_RIGHT);
	}

}

void draw(COORD posXY,char symbol) {
	/* Draw the screen */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
	printf("%c", symbol);

}

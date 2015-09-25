#pragma once
#include "stdafx.h"

void drawScreen() {
	/* Draw the screen */
	for (short i = 0; i < HEIGHT; i++) //Draw Top && Bottom
	{
		draw({ 0,i }, WALL);
		draw({ WIDTH-1,i }, WALL);
	}

	for (short i = 1; i < WIDTH; i++) //Draw Left && Right
	{
		draw({ i,0 }, WALL);
		draw({ i,HEIGHT-1 }, WALL);
	}

}

void draw(COORD posXY,char symbol) {
	/* Draw the something */
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), posXY);
	printf("%c", symbol);

}


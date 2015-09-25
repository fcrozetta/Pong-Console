// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TDE_Pong.h"

int main(){
	char buf[BUFSIZ];
	DWORD num_read;

	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List [2] = { &r1,&r2 };
	Dot d = Dot();
	

	drawScreen();
	initializeRacket(&r1, LEFT_SIDE);
	initializeRacket(&r2, RIGHT_SIDE);
	initializeDot(&d, UPLEFT);

	while (true) // Main loop
	{
		d.nextPos = d.posXY;
		nextPos(&d, d.direction);
		ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)buf, (DWORD)BUFSIZ, d.nextPos, (LPDWORD)&num_read);
		d.nextPosChar = buf[0];

		switch (d.nextPosChar)
		{
		case RACKET_BRUSH:
			draw({ 0,0 }, '!');
			break;
		case WALL:
			dotHitWall(&d);
			break;
		default:
			draw(d.posXY, SPACE);
			moveDot(&d);
			drawDot(&d);
			break;
		}

		if (_kbhit()) {
			char pressedKey = _getch();
			if (pressedKey == 'w'){
				moveRacket(&r1,UP);
			}
			if (pressedKey == 's')
			{
				moveRacket(&r1, DOWN);
			}
			if (pressedKey == 'i')
			{
				moveRacket(&r2, UP);
			}
			if (pressedKey == 'k')
			{
				moveRacket(&r2,DOWN);
			}

		}

		for (int i = 0; i < 2; i++)
		{
			if (List[i]->score >= 10)
			{
				system("cls");
				printf("Player %d Venceu!\n", i+1);
				_getch();
				return 0;
			}
		}
		Sleep(100);
	}
    return 0;
}
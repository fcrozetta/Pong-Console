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
	initializeDot(&d, LEFT);

	while (true) // Main loop
	{
		printScore(&r1, &r2);
		d.nextPos = d.posXY;
		nextPos(&d, d.direction);

		/* next position char*/
		ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)buf, (DWORD)BUFSIZ, d.nextPos, (LPDWORD)&num_read);
		d.nextPosChar = buf[0];

		/* char on the left and right side of the dot (Use this to know if you hit the racket*/
		ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)buf, (DWORD)BUFSIZ, { d.posXY.X - 1,d.posXY.Y }, (LPDWORD)&num_read);
		d.leftChar = buf[0];
		ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), (LPTSTR)buf, (DWORD)BUFSIZ, { d.posXY.X + 1,d.posXY.Y }, (LPDWORD)&num_read);
		d.rightChar = buf[0];

		/* Increment Score */
		if (d.nextPos.X == 0)
		{
			r2.score++;
			draw(d.posXY, SPACE);
			d.direction = UPLEFT;
			initializeDot(&d, d.direction);
			printScore(&r1, &r2);
			_getch();
		}
		if (d.nextPos.Y == WIDTH)
		{
			r1.score++;
			d.direction = UPRIGHT;
			initializeDot(&d, d.direction);
			printScore(&r1, &r2);
			_getch();
		}

		moveDot(&d, d.direction,List);
		drawDot(&d);
		

		/* Keyboard events */
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
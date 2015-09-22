// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//TODO: Remove matrix from code ... we will not need that anymore

int main(){
	/* Initialize scene and its objects */

	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List [2] = { &r1,&r2 };
	Dot ball = Dot();	
	//initializeDot(&ball, UPLEFT);
	initializeRacket(&r1, LEFT_SIDE);
	initializeRacket(&r2, RIGHT_SIDE);
	drawScreen();
	printf("its here");
	Sleep(10000);/*
	while (true) // Main loop
	{
		moveDot(screen, ball.direction, &ball, List);
		if (screen[ball.height][ball.width] == RACKET_BRUSH)
		{
			if (ball.width < (WIDTH/2))
			{
				dotHitRacket(screen,&ball, &r1, List);
			}
			else
			{
				dotHitRacket(screen,&ball, &r2, List);
			}
			
		}
		

		if (_kbhit()) {
			char pressedKey = _getch();
			if (pressedKey == 'w'){
				moveRacket(screen, &r1,UP);
			}
			if (pressedKey == 's')
			{
				moveRacket(screen, &r1, DOWN);
			}
			if (pressedKey == 'i')
			{
				moveRacket(screen, &r2, UP);
			}
			if (pressedKey == 'k')
			{
				moveRacket(screen,&r2,DOWN);
			}

		}

		for (int i = 0; i < 2; i++)
		{
			if (List[i]->score >= 10)
			{
				system("cls");
				printf("Player %d Venceu!\n", i+1);
				_getch;
				return 0;
			}
		}
	}*/
    return 0;
}


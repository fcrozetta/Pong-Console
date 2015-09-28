// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(){
	/* Initialize scene and its objects */

	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List [2] = { &r1,&r2 };
	boolean difficulty = false;
	r2.isplayer = gameMenu(&difficulty);
	r2.difficulty = difficulty;

	Dot ball = Dot();	
	char screen[HEIGHT][WIDTH];
	initializeRacket(screen, &r1, LEFT_SIDE);
	initializeRacket(screen, &r2, RIGHT_SIDE);
	initializeDot(screen, &ball, UPLEFT);
	
	while (true) // Main loop
	{
		initialize(screen);
		
		drawRacket(screen, &r1);
		drawRacket(screen, &r2);

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
			/* _kbhit is used to know if user pressed a button (keyboard) */
			char pressedKey = _getch();
			if (pressedKey == 'w'){
				moveRacket(screen, &r1,UP);
			}
			if (pressedKey == 's')
			{
				moveRacket(screen, &r1, DOWN);
			}
			//Check if the user choose pvp or pvc
			if (r2.isplayer) {
				//Choose multiplayer
				if (pressedKey == 'i')
				{
					moveRacket(screen, &r2, UP);
				}
				if (pressedKey == 'k')
				{
					moveRacket(screen, &r2, DOWN);
				}
			}
		}
		if (!r2.isplayer) {
			moveCPU(screen, &r2,ball.direction);
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
		draw(screen);
		sleep();
	}
    return 0;
}


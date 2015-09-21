// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	/* Initialize scene and its objects */

	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List [2] = { &r1,&r2 };

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
			if (pressedKey == 'i')
			{
				moveRacket(screen, &r2, UP);
			}
			if (pressedKey == 'k')
			{
				moveRacket(screen,&r2,DOWN);
			}
		}

		draw(screen);
		sleep();
	}
    return 0;
}


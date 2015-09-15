// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	/* Initialize scene and its objects */

	Racket r1 = Racket();
	Racket r2 = Racket();

	Dot ball = Dot();	
	char screen[HEIGHT][WIDTH];
	initializeRacket(screen, &r1, Side::LEFT_SIDE);
	initializeRacket(screen, &r2, Side::RIGHT_SIDE);
	initializeDot(screen, &ball, UPLEFT);
	

	while (true) // Main loop
	{
		initialize(screen);
		moveDot(screen, ball.direction, &ball);
		drawRacket(screen, &r1);
		drawRacket(screen, &r2);

		if (_kbhit()) {
			/* _kbhit is used to know if user pressed a button (keyboard) */
			char pressedKey = _getch();
			if (pressedKey == 'w'){
				moveRacket(screen, &r1,direction::UP);
			}
			if (pressedKey == 's')
			{
				moveRacket(screen, &r1, direction::DOWN);
			}
			if (pressedKey == 'i')
			{
				moveRacket(screen, &r2, direction::UP);
			}
			if (pressedKey == 'k')
			{
				moveRacket(screen,&r2,direction::DOWN);
			}
		}

		draw(screen);
		sleep();
	}
    return 0;
}


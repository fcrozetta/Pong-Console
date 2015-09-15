// TDE_Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	/* Initialize scene and its objects */

	Dot ball = Dot();
	char screen[HEIGHT][WIDTH];
	initialize(screen);
	initializeDot(screen, &ball, UPLEFT);
	

	while (true) // Main loop
	{
		moveDot(screen, ball.direction, &ball);

		if (_kbhit()) {
			/* _kbhit is used to know if user pressed a button (keyboard) */
			
			//TODO: Implement this main loop
			// code when something is pressed ...

		}

		draw(screen);
		sleep();
	}
    return 0;
}


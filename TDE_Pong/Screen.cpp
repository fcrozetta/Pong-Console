#pragma once
#include "stdafx.h"

void initialize(char screen[HEIGHT][WIDTH]) {
	int i, j;

	/* Creates walls on top and bottom */
	for ( i = 0; i < HEIGHT; i +=(HEIGHT-1))
	{
		for ( j = 0;  j < WIDTH;  j++)
		{
			screen[i][j] = WALL_TOP_BOTTOM;
		}
	}

	/* Creates walls on left and right sides */
	for ( i = 1; i < HEIGHT-1; i++)
	{
		for (j = 0; j < WIDTH; j += (WIDTH-1))
		{
			screen[i][j] = WALL_LEFT_RIGHT;
		}
	}

	/* Creates Empty spaces in the middle */
	for (i = 1; i < HEIGHT-1; i++)
	{
		for (j = 1; j < WIDTH-1; j++)
		{
			screen[i][j] = SPACE;
		}
	}
}

void draw(char screen[HEIGHT][WIDTH]) {
	/* Draw the screen */
	clear();
	int i, j;
	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			printf("%c", screen[i][j]);
		}
		printf("\n");
	}
}
//Menu - Player versus player 
void PvP() {

	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List[2] = { &r1,&r2 };

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
			if (ball.width < (WIDTH / 2))
			{
				dotHitRacket(screen, &ball, &r1, List);
			}
			else
			{
				dotHitRacket(screen, &ball, &r2, List);
			}

		}


		if (_kbhit()) {
			/* _kbhit is used to know if user pressed a button (keyboard) */
			char pressedKey = _getch();
			if (pressedKey == 'w') {
				moveRacket(screen, &r1, UP);
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
				moveRacket(screen, &r2, DOWN);
			}

		}

		for (int i = 0; i < 11; i++)
		{
			if (List[i]->score >= 10)
			{
				system("cls");
				printf("Player %d Venceu!\n", i + 1);
				_getch;
				break;
			}
		}
		draw(screen);
		sleep();
	}
}
//Menu - Player versus Computer
void PvC() {
	Racket r1 = Racket();
	Racket r2 = Racket();
	Racket * List[2] = { &r1,&r2 };

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

		moveDotPvC(screen, ball.direction, &ball, List);
		if (screen[ball.height][ball.width] == RACKET_BRUSH)
		{
			if (ball.width < (WIDTH / 2))
			{
				dotHitRacket(screen, &ball, &r1, List);
			}
			else
			{
				dotHitRacket(screen, &ball, &r2, List);
			}

		}


		if (_kbhit()) {
			/* _kbhit is used to know if user pressed a button (keyboard) */
			char pressedKey = _getch();
			if (pressedKey == 'w') {
				moveRacket(screen, &r1, UP);
			}
			if (pressedKey == 's')
			{
				moveRacket(screen, &r1, DOWN);
			}
		}

		for (int i = 0; i < 2; i++)
		{
			if (List[i]->score >= 10)
			{
				system("cls");
				printf("Player %d Venceu!\n", i + 1);
				_getch;
				break;
			}
		}
		draw(screen);
		sleep();
	}
}

void gameMenu(char screen[HEIGHT][WIDTH]) {
	printf("-----------------------------------------------------------------------------\n");
	printf("--           ===========  ===========  ===      ==  ==========             --\n");
	printf("--           ==       ==  ==       ==  == =     ==  ==                     --\n");
	printf("--           ==       ==  ==       ==  ==  =    ==  ==                     --\n");
	printf("--           ===========  ==       ==  ==   =   ==  ==  ======             --\n");
	printf("--           ==           ==       ==  ==    =  ==  ==  ==  ==             --\n");
	printf("--           ==           ==       ==  ==     = ==  ==  ==  ==             --\n");
	printf("--           ==           ===========  ==      ===  ==========             --\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("--                                                                         --\n");
	printf("--                 CHOOSE 'A' FOR PLAYER VERSUS PLAYER                     --\n");
	printf("-----------------                                       ---------------------\n");
	printf("-----------------                                       ---------------------\n");
	printf("--                CHOOSE 'B' FOR PLAYER VERSUS COMPUTER                    --\n");
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("-----------------------------------------------------------------------------\n");
	while (true) {
		if (_kbhit()) {
			/* _kbhit is used to know if user pressed a button (keyboard) */
			char pressedKey = _getch();
			if (pressedKey == '1') {
				PvP();
				break;
			}
			if (pressedKey == 'b')
			{
				PvC();
				break;
			}
		}
		sleep();
	}
}
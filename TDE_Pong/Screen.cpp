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
	for (i = 0; i != HEIGHT; i++) {
		screen[i][WIDTH / 2] = '.';
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

bool gameMenu(boolean * difficulty) {
	int choose, d = 1;
	printf("Choose 1 for singleplayer or 2 for multiplayer : ");
	scanf_s("%d", &choose);
	if (choose == 1) {
		printf("Choose 1 for difficulty easy or 2 for expert : ");
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
		printf("--                 CHOOSE '1' FOR PLAYER VERSUS PLAYER                     --\n");
		printf("-----------------                                       ---------------------\n");
		printf("-----------------                                       ---------------------\n");
		printf("--                CHOOSE '2' FOR PLAYER VERSUS COMPUTER                    --\n");
		printf("--                                                                         --\n");
		printf("--                                                                         --\n");
		printf("--                                                                         --\n");
		printf("--                                                                         --\n");
		printf("--                                                                         --\n");
		printf("-----------------------------------------------------------------------------\n");
		scanf_s("%d", &choose);
		if (choose == 1) {
			clear();
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
			printf("--                    CHOOSE '1' FOR DIFFICULTY EASY                       --\n");
			printf("-----------------                                       ---------------------\n");
			printf("-----------------                                       ---------------------\n");
			printf("--                   CHOOSE '2' FOR DIFFICULTY EXPERT                      --\n");
			printf("--                                                                         --\n");
			printf("--                                                                         --\n");
			printf("--                                                                         --\n");
			printf("--                                                                         --\n");
			printf("--                                                                         --\n");
			printf("-----------------------------------------------------------------------------\n");
			scanf_s("%d", &d);
		}
		if (d == 2) {
			*difficulty = true;
		}
		if (choose == 1) {
			return false;
		}
		
	}
	return true;
}
void printScore(int p1,int p2){
	clear();
	printf("-----------------------------------------------------------------------------\n");
	printf("--         ========  =========== ===========  ===========  ==========      --\n");
	printf("--         ==        ==          ==       ==  ==       ==  ==              --\n");
	printf("--         ==        ==          ==       ==  ==       ==  ==              --\n");
	printf("--         =======   ==          ==       ==  ===========  ======          --\n");
	printf("--              ==   ==          ==       ==  ==   ==      ==              --\n");
	printf("--              ==   ==          ==       ==  ==    ==     ==              --\n");
	printf("--         =======   =========== ===========  ==      ===  ==========      --\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("--                                                                         --\n");
	printf("--                            PLAYER 1  :  %d                              --\n", p1);
	printf("-----------------                                       ---------------------\n");
	printf("-----------------                                       ---------------------\n");
	printf("--                            PLAYER 2  :  %d                              --\n", p2);
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("--                                                                         --\n");
	printf("--                       PRESS ANY KEY TO CONTINUE                         --\n");
	printf("--                                                                         --\n");
	printf("-----------------------------------------------------------------------------\n");
	_getch();
}
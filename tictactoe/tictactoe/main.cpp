#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "input.h"
#include "main.h"
#include "conio.h"

void main()
{
	char board[3][3] = { '1', '2', '3',
		'4', '5', '6',
		'7', '8', '9' };

	printf("Player (X) = 1 - Player (O) = 2\n");
	printf("-------------------------------\n");
	printf("Here is the tictactoe board\n\n");

	playlogic(board);

	_getch();

	return;
}
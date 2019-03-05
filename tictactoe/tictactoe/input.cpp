#include <stdio.h>

void drawboard(char board[3][3])
{
	printf("\t _______________________ \n");
	printf("\t|       |       |       |\n");
	printf("\t|   %c   |   %c   |   %c   |\n", board[0][0], board[0][1], board[0][2]);
	printf("\t|_______|_______|_______|\n");
	printf("\t|       |       |       |\n");
	printf("\t|   %c   |   %c   |   %c   |\n", board[1][0], board[1][1], board[1][2]);
	printf("\t|_______|_______|_______|\n");
	printf("\t|       |       |       |\n");
	printf("\t|   %c   |   %c   |   %c   |\n", board[2][0], board[2][1], board[2][2]);
	printf("\t|_______|_______|_______|\n");
}

// draw the board and ask human_player for next move
void screen(char board[3][3])
{
	int played_cell;

	drawboard(board);

	printf("Human player choose cell: ");

	scanf("%d", &played_cell);

	board[played_cell / 3][played_cell % 3 - 1] = 'X';

	return;
}
#include <stdio.h>

// return a value for who is winning
int evaluate(char board[3][3])
{
	int row, col;

	// check for rows
	for (row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
		{
			if (board[row][0] == 'O')
				return 10;
			if (board[row][0] == 'X')
				return -10;
		}
	}

	// check for col
	for (col = 0; col < 3; col++)
	{
		if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
		{
			if (board[0][col] == 'O')
				return 10;
			if (board[0][col] == 'X')
				return -10;
		}
	}

	// check for main diagonal
	if (board[1][1] == board[0][0] && board[1][1] == board[2][2])
	{
		if (board[0][0] == 'O')
			return 10;
		if (board[0][0] == 'X')
			return -10;
	}

	// check for sub diagonal
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
	{
		if (board[1][1] == 'O')
			return 10;
		if (board[1][1] == 'X')
			return -10; 
	}

	// if no player won
	return 0;
}


#include <stdio.h>
#include "main.h"
#include "input.h"
#include "output.h"

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

// check if there are any moves left
bool isMoveleft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;
		}
	}

	return false;
}

// Human play x, pc play o
// depth is the depth of the pc calculation
int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	// check if the game is finish and there is a winner
	if (score == 10 || score == -10)
	{
		return score;
	}

	// check if the game is a tie
	if (!isMoveleft(board))
		return 0;

	// if this is maximizer turn
	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// check if the cell is empty
				if (board[i][j] != 'X' && board[i][j] != 'O')
				{
					// maximizer plays move
					board[i][j] = 'O';

					// call minimax recursive and choose the max value
					best = max(best, minimax(board, depth + 1, !isMax));

					// undo the move
					board[i][j] = '0' + i * 3 + j + 1;
				}
			}
		}

		return best;
	}

	// if this is minimizer turn
	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				// check if the cell is empty
				if (board[i][j] != 'X' && board[i][j] != 'O')
				{
					// minimizer plays move
					board[i][j] = 'X';

					// call minimax recursive and choose the minimum move
					best = min(best, minimax(board, depth + 1, !isMax));

					// undo move
					board[i][j] = '0' + i * 3 + j + 1;
				}
			}
		}

		return best;
	}
}

move findBestmove(char board[3][3])
{
	int bestVal = -1000;
	move bestMove;
	bestMove.col = -1;
	bestMove.row = -1;

	// traverse all cell and return the cell with best value
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// check if the cell is empty
			if (board[i][j] != 'X' && board[i][j] != 'O')
			{
				// pc make the move
				board[i][j] = 'O';

				// value of this position
				int moveVal = minimax(board, 0, false);

				// undo the move
				board[i][j] = '0' + i * 3 + j + 1;

				// compare the value of the current move with best value and update
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}

void playlogic(char board[3][3])
{
	move pc_move;

	// go through every stage of the game
	while (isMoveleft(board) && evaluate(board) != 10 && evaluate(board) != -10)
	{
		// print the current stage of the game
		screen(board);

		// find the best move for pc
		pc_move = findBestmove(board);

		if (pc_move.col != -1 && pc_move.row != -1)
			board[pc_move.row][pc_move.col] = 'O';
	}

	if (evaluate(board) == 10)
	{
		drawboard(board);

		printf("PC won the game\n");
	}
	else if (evaluate(board) == -10)
	{
		drawboard(board);

		printf("Human won the game\n");
	}
	else
	{
		drawboard(board);

		printf("Tie\n");
	}

	return;
}




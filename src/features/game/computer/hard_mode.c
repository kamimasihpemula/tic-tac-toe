#include "hard_mode.h"

void hard_mode(char board[][BOARD_SIZE], int size)
{
    int bestMoveRow = -1;
    int bestMoveCol = -1;
    int bestScore = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int moveScore = minimax(board, 0, 0, INT_MIN, INT_MAX, size);
                board[i][j] = ' ';

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    Sleep(2000);
    board[bestMoveRow][bestMoveCol] = 'O';
    Beep(900, 300); // Play sound for player 2
}

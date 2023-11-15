#include "minimax.h"
int minimax(char board[][BOARD_SIZE], int depth, int isMaximizing, int alpha, int beta, int size)
{
    // Terminal node evaluation
    if (check_win(board, size, 'X'))
        return -1;
    if (check_win(board, size, 'O'))
        return 1;
    if (check_tie(board, size))
        return 0;

    if (size == 3)
    {
        if (depth >= size * size)
            return 0; // Adjust the depth for a larger board
    }
    else
    {
        if (depth >= 4)
            return 0; // Adjust the depth for a larger board
    }

    if (isMaximizing)
    {
        int maxEval = INT_MIN;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    int eval = minimax(board, depth + 1, 0, alpha, beta, size);
                    maxEval = (eval > maxEval) ? eval : maxEval;
                    alpha = (eval > alpha) ? eval : alpha;
                    board[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return maxEval;
    }
    else
    {
        int minEval = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    int eval = minimax(board, depth + 1, 1, alpha, beta, size);
                    minEval = (eval < minEval) ? eval : minEval;
                    beta = (eval < beta) ? eval : beta;
                    board[i][j] = ' ';
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return minEval;
    }
}

#include "win_validator.h"

int check_win(char board[][BOARD_SIZE], int size, char player)
{
    int consecutive = size == 3 ? 3 : (size == 5 ? 4 : 5);

    // Check horizontal and vertical lines for consecutive markers
    for (int i = 0; i < size; i++)
    {
        int row_win = 0, col_win = 0;
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == player)
                row_win++;
            else
                row_win = 0;

            if (board[j][i] == player)
                col_win++;
            else
                col_win = 0;

            if (row_win >= consecutive || col_win >= consecutive)
                return 1;
        }
    }

    // Check diagonals for consecutive markers
    for (int i = 0; i <= size - consecutive; i++)
    {
        for (int j = 0; j <= size - consecutive; j++)
        {
            int diag1_win = 0, diag2_win = 0;
            for (int k = 0; k < consecutive; k++)
            {
                if (board[i + k][j + k] == player)
                    diag1_win++;
                else
                    diag1_win = 0;

                if (board[i + k][j + consecutive - 1 - k] == player)
                    diag2_win++;
                else
                    diag2_win = 0;

                if (diag1_win >= consecutive || diag2_win >= consecutive)
                    return 1;
            }
        }
    }

    return 0;
}

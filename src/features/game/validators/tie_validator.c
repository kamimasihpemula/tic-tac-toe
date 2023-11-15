#include "tie_validator.h"

int check_tie(char board[][BOARD_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
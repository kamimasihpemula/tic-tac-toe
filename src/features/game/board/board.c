#include "board.h"

void display_board(char board[][BOARD_SIZE], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < size - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < size - 1)
        {
            for (int k = 0; k < size * 4 - 1; k++)
                printf("-");
            printf("\n");
        }
    }
    printf("\n");
}

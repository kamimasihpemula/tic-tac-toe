#include "player2.h"

void get_user_move2(char board[][BOARD_SIZE], int size)
{
    int row, col;
    printf("Enter row (1-%d): ", size);
    scanf("%d", &row);
    printf("Enter column (1-%d): ", size);
    scanf("%d", &col);
    row--;
    col--;
    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ')
    {
        printf("Invalid move. Try again.\n");
        get_user_move2(board, size);
    }
    else
    {
        board[row][col] = 'O';
        Beep(700, 500); // Play sound for player 2
    }
}
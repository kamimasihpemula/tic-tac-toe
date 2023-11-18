#include "player.h"

void get_player_move(char board[][BOARD_SIZE], int size, char player)
{
    int row, col;
    printf("Enter row (1-%d): ", size);
    scanf("%d", &row);
    printf("Enter column (1-%d): ", size);
    scanf("%d", &col);
    printf("\n");
    row--;
    col--;
    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ')
    {
        printf("Invalid move. Try again.\n");
        get_player_move(board, size, player);
    }
    else
    {
        board[row][col] = player;
        player == 'X' ? Beep(700, 500) : Beep(900, 500);
    }
}

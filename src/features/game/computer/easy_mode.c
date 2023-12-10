#include "easy_mode.h"

void easy_mode(char board[][BOARD_SIZE], int size)
{
    int row, col;
    do
    {
        row = rand() % size;
        col = rand() % size;
    } while (board[row][col] != ' ');
    //Sleep(2000);
    board[row][col] = 'O';
    //Beep(900, 300); // Play sound for player 2
}

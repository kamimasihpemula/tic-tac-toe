#include "over_validator.h"

int is_game_over(char board[][BOARD_SIZE], int size)
{
    return (check_win(board, size, 'X') || check_win(board, size, 'O') || check_tie(board, size));
}
#include "computer.h"
#include "easy_mode.h"
#include "hard_mode.h"

void get_computer_move(char board[][BOARD_SIZE], int size, int mode)
{
    mode == 1 ? easy_mode(board, size) : hard_mode(board, size);
}

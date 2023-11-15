#ifndef minimax_h
#define minimax_h

#include "../../../main.h"
#include <limits.h>
#include "../validators/over_validator.h"

int minimax(char board[][BOARD_SIZE], int depth, int isMaximizing, int alpha, int beta, int size);

#endif
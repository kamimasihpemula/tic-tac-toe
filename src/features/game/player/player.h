#ifndef player_h
#define player_h

#include "../../../main.h"
#include "../game.h"

int get_player_move(char board[][BOARD_SIZE], int size, char player, int vs, User *user);

#endif
#ifndef menu_h
#define menu_h

#include <stdio.h>
#include "../game/game.h"

void display_menu();
void start_game(Histories *data, User *user, Sound sound[6]);
void display_score(int game_mode, Histories *data);
void display_history(Histories data, User user);

#endif
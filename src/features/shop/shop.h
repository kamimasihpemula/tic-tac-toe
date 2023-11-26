#ifndef shop_h
#define shop_h

#include <stdio.h>
#include "../game/game.h"

void shop(User *user, Sound sound[6], Histories *histories);
void buy_sound(User *user, Sound sound[6]);

#endif
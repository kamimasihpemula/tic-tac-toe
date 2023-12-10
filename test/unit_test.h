#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "unity/src/unity.h"
#include "../src/main.h"
#include "../src/features/game/game.h"
#include "../src/features/game/validators/over_validator.h"
#include "../src/features/game/player/player.h"
#include "../src/features/game/computer/computer.h"
#include "../src/features/game/states/save_game.h"
#include "../src/features/menu/menu.h"
#include "../src/features/cover/cover.h"

// Helper function to initialize the board for testing
void initialize_board(char board[][BOARD_SIZE], int size);

// Test setup and teardown functions
void setUp(void);
void tearDown(void);

// Test cases
void test_update_user_coins(void);
void test_check_win(void);
void test_check_tie(void);

// Add more test cases...

#endif // UNIT_TEST_H

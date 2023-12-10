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
void initialize_board(char board[][BOARD_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void setUp(void)
{
    // Optional: Add any setup code here
}

void tearDown(void)
{
    // Optional: Add any teardown code here
}

void test_update_user_coins()
{
    User user = {.coins = 0};
    add_user_point(&user, 11);
    TEST_ASSERT_EQUAL_INT(10, user.coins);
}

// Test the check_win function
void test_check_win()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int size = 3;

    // Test horizontal win
    initialize_board(board, size);
    board[0][0] = board[0][1] = board[0][2] = 'X';
    TEST_ASSERT_EQUAL_INT(1, check_win(board, size, 'X'));

    // Test vertical win
    initialize_board(board, size);
    board[0][0] = board[1][0] = board[2][0] = 'O';
    TEST_ASSERT_EQUAL_INT(1, check_win(board, size, 'O'));

    // Test diagonal win
    initialize_board(board, size);
    board[0][0] = board[1][1] = board[2][2] = 'X';
    TEST_ASSERT_EQUAL_INT(1, check_win(board, size, 'X'));
}

// Test the check_tie function
void test_check_tie()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int size = 3;

    // Test non-tie situation
    initialize_board(board, size);
    board[0][0] = 'X';
    TEST_ASSERT_EQUAL_INT(0, check_tie(board, size));

    // Test tie situation
    initialize_board(board, size);
    board[0][0] = board[0][1] = board[0][2] = 'X';
    board[1][0] = board[1][1] = board[1][2] = 'O';
    board[2][0] = board[2][1] = board[2][2] = 'X';
    TEST_ASSERT_EQUAL_INT(1, check_tie(board, size));
}

//! Uncomment this line to run the unit tests
// int main(void)
// {
//     UNITY_BEGIN();

//     RUN_TEST(test_check_win);
//     RUN_TEST(test_check_tie);
//     RUN_TEST(test_update_user_coins);

//     return UNITY_END();
// }

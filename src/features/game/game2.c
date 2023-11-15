#include "game2.h"
#include "board/board.h"
#include "../../main.h"
#include "validators/over_validator.h"
#include "player/player.h"
#include "player/player2.h"
#include "../../global.h"

void play_game2(int size, int mode)
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    int turn = 0;
    while (!is_game_over(board, size))
    {
        if (turn % 2 == 0)
        {
            if (turn != 0)
            {
                printf("Player 2 Move");
            }
            display_board(board, size);
            get_user_move(board, size);
            if (check_win(board, size, 'X'))
            {
                display_board(board, size);
                printf("Player 1 win!\n");
                user_score++;
                break;
            }
        }
        else
        {
            printf("Player 1 Move");
            display_board(board, size);
            get_user_move2(board, size);
            if (check_win(board, size, 'O'))
            {
                display_board(board, size);
                printf("Player 2 wins!\n");
                computer_score++;
                break;
            }
        }
        if (check_tie(board, size))
        {
            display_board(board, size);
            printf("Tie game!\n");
            break;
        }
        turn++;
    }
    printf("Final score: Player 1 %d - %d Player 2\n", user_score, computer_score);
}

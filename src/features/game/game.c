#include "game.h"
#include "board/board.h"
#include "../../main.h"
#include "validators/over_validator.h"
#include "player/player.h"
#include "computer/computer.h"
#include "../../global.h"

void play_game(int size, int mode, int vs)
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
                vs == 2 ? printf("Player 2 Move") : printf("Computer Move");

            display_board(board, size);
            get_player_move(board, size, 'X');
            if (check_win(board, size, 'X'))
            {
                display_board(board, size);
                printf("You win!\n");
                user_score++;
                break;
            }
        }
        else
        {
            printf("Your Move");
            display_board(board, size);
            vs == 2 ? get_player_move(board, size, 'O') : get_computer_move(board, size, mode);
            if (check_win(board, size, 'O'))
            {
                display_board(board, size);
                vs == 2 ? printf("Player 2 wins!\n") : printf("Computer wins!\n");
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
    vs == 2 ? printf("Final score: Player 1 %d - %d Player 2\n", user_score, computer_score) : printf("Final score: You %d - %d Computer\n", user_score, computer_score);
}
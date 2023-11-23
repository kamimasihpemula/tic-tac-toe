#include "game.h"
#include "board/board.h"
#include "../../main.h"
#include "validators/over_validator.h"
#include "player/player.h"
#include "computer/computer.h"
#include "../../global.h"
#include "states/save_game.h"

Histories histories;
History leaderboard[MAX_HISTORY_SIZE];
int history_count = 0;

void play_game(int size, int mode, int vs)
{
    int statusGame = 0;
    vs == 1 ? pvc(size, mode, &statusGame) : pvp(size);
    // Inside the play_game function after the game loop
    if (statusGame == 1)
    {
        add_to_leaderboard("You", "Win", 10);
    }
    else if (statusGame == 0)
    {

        add_to_leaderboard("You", "Lose", 0);
    }
    else
    {
        add_to_leaderboard("You", "Tie", 0);
    }
    save_game();
}

void pvp(int size)
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
    int isSkip = 0;
    while (!is_game_over(board, size))
    {
        if (turn % 2 == 0)
        {
            if (turn == 0)
                display_board(board, size);
            if (isSkip == 0 && turn != 0)
            {
                printf("Player 2 Move");
                display_board(board, size);
            }
            printf("Player 1 Turn\n");
            isSkip = get_player_move(board, size, 'X', 2);
            if (check_win(board, size, 'X'))
            {
                display_board(board, size);
                printf("Player 1 wins!\n");
                break;
            }
        }
        else
        {
            if (isSkip == 0)
            {
                printf("Player 1 Move");
                display_board(board, size);
            }
            printf("Player 2 Turn\n");
            isSkip = get_player_move(board, size, 'O', 2);
            if (check_win(board, size, 'O'))
            {
                display_board(board, size);
                printf("Player 2 wins!\n");
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
}

void pvc(int size, int mode, int *statusGame)
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
    int isSkip = 0;
    while (!is_game_over(board, size))
    {
        if (turn % 2 == 0)
        {
            if (turn != 0)
                printf("Computer Move");

            display_board(board, size);
            isSkip = get_player_move(board, size, 'X', 1);
            if (check_win(board, size, 'X'))
            {
                display_board(board, size);
                printf("You win!\n");
                *statusGame = 1;
                user_score++;
                break;
            }
        }
        else
        {
            if (isSkip == 0)
            {
                printf("Your Move");
                display_board(board, size);
            }
            get_computer_move(board, size, mode);
            if (check_win(board, size, 'O'))
            {
                display_board(board, size);
                printf("Computer wins!\n");
                computer_score++;
                break;
            }
        }
        if (check_tie(board, size))
        {
            display_board(board, size);
            printf("Tie game!\n");
            *statusGame = 2;
            break;
        }
        turn++;
    }
}

void add_to_leaderboard(char username[], char result[], int coins)
{
    history_count = histories.count;
    if (history_count < MAX_HISTORY_SIZE)
    {
        // Get current time
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        // Save to leaderboard
        sprintf(leaderboard[history_count].username, "%s", username);
        sprintf(leaderboard[history_count].result, "%s", result);
        sprintf(leaderboard[history_count].datetime, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
        sprintf(leaderboard[history_count].time, "%02d:%02d", tm.tm_hour, tm.tm_min);
        leaderboard[history_count].coins = coins;
        histories.count = history_count + 1;

        histories.history[history_count] = leaderboard[history_count];

        // Update history count
        history_count++;
    }
    else
    {
        printf("Leaderboard is full. Unable to add more entries.\n");
    }
}
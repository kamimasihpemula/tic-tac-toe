#include "player.h"
#include <time.h>
#define TIME_LIMIT 10

int get_player_move(char board[][BOARD_SIZE], int size, char player, int vs, User *user, double elapsed_time)
{
    int isSkip = 0;
    time_t start_time, current_time;

    time(&start_time); // Record the start time

    // Get player's move
    int row, col;
    printf("Enter row (1-%d): ", size);
    scanf("%d", &row);
    printf("Enter column (1-%d): ", size);
    scanf("%d", &col);
    printf("\n");
    row--;
    col--;

    // Check elapsed time
    time(&current_time);
    elapsed_time += difftime(current_time, start_time);

    // If the elapsed time exceeds the time limit, print a message and move on to the computer's turn
    if (elapsed_time > TIME_LIMIT)
    {
        if (vs == 1)
        {
            printf("Time limit exceeded. Computer's turn.\n");
            // Beep(1000, 700);
            // play_sound(user);
        }
        else
        {
            player == 'X' ? printf("Time limit exceeded. Player 2's turn.\n") : printf("Time limit exceeded. Player 1's turn.\n");
            // Beep(1000, 700);
            // play_sound(user);
        }
        isSkip = 1;
    }
    else
    {
        if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ')
        {
            printf("Invalid move. Try again.\n");
            get_player_move(board, size, player, vs, user, elapsed_time);
        }
        else
        {
            board[row][col] = player;
            // player == 'X' ? Beep(700, 500) : Beep(900, 500);
            player == 'X' ? play_sound(user) : Beep(900, 500);
            isSkip = 0;
        }
    }
    return isSkip;
}

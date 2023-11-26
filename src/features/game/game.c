#include "game.h"
#include "board/board.h"
#include "../../main.h"
#include "validators/over_validator.h"
#include "player/player.h"
#include "computer/computer.h"
#include "states/save_game.h"

void play_game(int size, int mode, int vs, Histories *histories, User *user, Sound sound[6])
{
    int statusGame = 0;
    vs == 1 ? pvc(size, mode, &statusGame, histories, user) : pvp(size, user);
    // Inside the play_game function after the game loop
    History data;
    if (statusGame == 1)
    {
        int point = 0;
        if (mode == 2)
        {
            if (size == 3)
                point = 10;
            else if (size == 5)
                point = 15;
            else
                point = 25;
        }
        else
        {
            if (size == 3)
                point = 5;
            else if (size == 5)
                point = 10;
            else
                point = 20;
        }
        data = (History){
            .username = "You",
            .game = (vs == 1) ? "Singleplayer" : "Multiplayer",
            .level = (mode == 1) ? "Easy" : "Hard",
            .result = "Win",
            .coins = point};
        add_user_point(user, point);
        add_to_leaderboard(data, histories);
    }
    else if (statusGame == 0)
    {
        data = (History){
            .username = "You",
            .game = (vs == 1) ? "Singleplayer" : "Multiplayer",
            .level = mode == 1 ? "Easy" : "Hard",
            .result = "Lose",
            .coins = 0};
        add_to_leaderboard(data, histories);
    }
    else
    {
        data = (History){
            .username = "You",
            .game = (vs == 1) ? "Singleplayer" : "Multiplayer",
            .level = (mode == 1) ? "Easy" : "Hard",
            .result = "Tie",
            .coins = 0};
        add_to_leaderboard(data, histories);
    }
    save_game(histories, user, sound);
}

void pvp(int size, User *user)
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
            isSkip = get_player_move(board, size, 'X', 2, user);
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
            isSkip = get_player_move(board, size, 'O', 2, user);
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

void pvc(int size, int mode, int *statusGame, Histories *data, User *user)
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
            isSkip = get_player_move(board, size, 'X', 1, user);
            if (check_win(board, size, 'X'))
            {
                display_board(board, size);
                printf("You win!\n");
                *statusGame = 1;
                data->user_score++;
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
                data->computer_score++;
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

void add_user_point(User *user, int point)
{
    user->coins += point;
}

void add_to_leaderboard(History data, Histories *histories)
{

    char *time = get_current_time();
    char *date = get_current_date();

    if (histories->size < MAX_HISTORY_SIZE)
    {
        strcpy(data.time, time);
        strcpy(data.date, date);
        histories->history[histories->size] = data;
        histories->size++;
    }
    else
    {
        for (int i = 0; i < MAX_HISTORY_SIZE - 1; i++)
        {
            histories->history[i] = histories->history[i + 1];
        }
        strcpy(data.time, time);
        strcpy(data.date, date);
        histories->history[MAX_HISTORY_SIZE - 1] = data;
    }
    free(time);
    free(date);
}

char *get_current_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *time = malloc(20 * sizeof(char));
    sprintf(time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    return time;
}

char *get_current_date()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *date = malloc(20 * sizeof(char));
    sprintf(date, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return date;
}

void play_sound(User *user)
{
    char *soundFile;
    char *temp = user->sound.name;

    // Assuming user->sound is a null-terminated string
    if (strcmp(temp, "Default") != 0)
    {
        soundFile = malloc(strlen(temp) + 5);
        strcpy(soundFile, temp);
        strcat(soundFile, ".mp3");
        // add assets/sounds/ to the path
        char *path = "assets/sounds/";
        char *soundPath = malloc(strlen(path) + strlen(soundFile) + 1);
        strcpy(soundPath, path);
        strcat(soundPath, soundFile);

        // Construct the MCI command to play the MP3 file
        char command[256];
        snprintf(command, sizeof(command), "open \"%s\" type mpegvideo alias mp3", soundPath);

        // Open the MP3 file
        mciSendString(command, NULL, 0, NULL);

        // Play the MP3 file
        mciSendString("play mp3", NULL, 0, NULL);

        // Wait for the playback to finish (you can adjust this time)
        Sleep(5000);

        // Close the MP3 file
        mciSendString("close mp3", NULL, 0, NULL);
    }
    else
    {
        Beep(1000, 700);
    }
}
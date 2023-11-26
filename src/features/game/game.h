#ifndef game_h
#define game_h

#include <stdio.h>
#include <windows.h>

#define FILENAME "data.bin"
#define MAX_HISTORY_SIZE 100

typedef struct
{
    char *name;
    int price;
    char *purchased;
} Sound;

typedef struct
{
    int coins;
    Sound sound;
} User;

typedef struct
{
    char date[20];
    char time[6];
    char *username;
    char *game;
    char *level;
    char *result;
    int coins;
} History;

typedef struct
{
    History history[MAX_HISTORY_SIZE];
    int size;
    int user_score;
    int computer_score;
} Histories;

void play_game(int size, int mode, int vs, Histories *histories, User *user, Sound sound[6]);
void pvp(int size, User *user);
void pvc(int size, int mode, int *statusGame, Histories *data, User *user);
void add_user_point(User *user, int point);
void add_to_leaderboard(History data, Histories *histories);
void play_sound(User *user);
char *get_current_time();
char *get_current_date();

#endif
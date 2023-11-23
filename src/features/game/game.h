#ifndef game_h
#define game_h

#include <stdio.h>

#define FILENAME "../GAME.DAT"
#define MAX_HISTORY_SIZE 100

typedef struct
{
    char username[50];
    char result[20];
    char datetime[20];
    char time[6];
    int coins;
} History;

typedef struct
{
    History history[MAX_HISTORY_SIZE];
    int count;
} Histories;

extern Histories histories;
extern History leaderboard[MAX_HISTORY_SIZE];
extern int history_count;

void play_game(int size, int mode, int vs);
void pvp(int size);
void pvc(int size, int mode, int *statusGame);
void add_to_leaderboard(char username[], char result[], int coins);

#endif
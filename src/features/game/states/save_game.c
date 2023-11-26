#include "save_game.h"

void save_game(Histories *histories, User *user, Sound sound[6])
{
    FILE *file = fopen(FILENAME, "wb");

    if (file != NULL)
    {
        fwrite(histories, sizeof(Histories), 1, file);
        fwrite(user, sizeof(User), 1, file);
        fwrite(sound, sizeof(Sound), 6, file);
        fclose(file);
    }
    else
    {
        printf("Unable to open file for writing.\n");
    }
}
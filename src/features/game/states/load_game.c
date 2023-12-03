#include "load_game.h"

int load_game(Histories *histories, User *user, Sound sound[6])
{
    FILE *file = fopen(FILENAME, "rb");

    if (file != NULL)
    {
        fread(histories, sizeof(Histories), 1, file);
        fread(user, sizeof(User), 1, file);
        fread(sound, sizeof(Sound), 6, file);
        fseek(file, 0, SEEK_SET);
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}
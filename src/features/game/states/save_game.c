#include "save_game.h"
#include "../game.h"

void save_game()
{
    FILE *file = fopen(FILENAME, "wb");

    if (file != NULL)
    {
        fwrite(&histories, sizeof(Histories), 1, file);
        fclose(file);
    }
    else
    {
        printf("Unable to open file for writing.\n");
    }
}
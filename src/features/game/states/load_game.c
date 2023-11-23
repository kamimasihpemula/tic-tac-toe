#include "load_game.h"
#include "../game.h"

void load_game()
{
    FILE *file = fopen(FILENAME, "rb");

    if (file != NULL)
    {
        fread(&histories, sizeof(Histories), 1, file);
        fclose(file);
    }
    else
    {
        printf("Unable to open file for reading.\n");
    }
}
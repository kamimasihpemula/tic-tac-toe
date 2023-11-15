#include "main.h"
#include "features/menu/menu.h"

#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    printf("Welcome to Tic Tac Toe!\n");

    display_menu();

    return 0;
}

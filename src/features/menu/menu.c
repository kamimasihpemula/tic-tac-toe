#include "../../main.h"
#include "menu.h"
#include "../game/game.h"
#include "../../global.h"

void display_menu()
{
    while (1)
    {
        int size, mode;
        printf("Choose the board size (3, 5, or 7): ");
        scanf("%d", &size);
        if (size != 3 && size != 5 && size != 7)
        {
            printf("Invalid board size. Please choose 3, 5, or 7.\n");
            continue;
        }

        printf("Choose the mode (1 - Easy, 2 - Hard): ");
        scanf("%d", &mode);
        if (mode != 1 && mode != 2)
        {
            printf("Invalid mode. Please choose 1 (Easy) or 2 (Hard).\n");
            continue;
        }

        play_game(size, mode);

        printf("Play again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {

            printf("High scores:\n");
            printf("You: %d - Computer: %d\n", user_score, computer_score);
            break;
        }
    }
}
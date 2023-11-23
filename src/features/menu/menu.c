#include "../../main.h"
#include "menu.h"
#include "../game/game.h"
#include "../../global.h"
#include "../game/states/save_game.h"
#include "../game/states/load_game.h"

void display_menu()
{
    while (1)
    {
        printf("1. Play Game\n");
        printf("2. Load Game\n");
        printf("3. History Game\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start_game();
            break;
        case 2:
            load_game();
            break;
        case 3:
            display_history();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void start_game()
{

    while (1)
    {
        int vs;
        printf("Choose the game mode (1 - Singleplayer, 2 - Multiplayer): ");
        scanf("%d", &vs);
        if (vs != 1 && vs != 2)
        {
            printf("Invalid game mode. Please choose 1 or 2.\n");
            continue;
        }
        int size, mode;

        if (vs == 1)
        {
            printf("Choose the mode (1 - Easy, 2 - Hard): ");
            scanf("%d", &mode);
            if (mode != 1 && mode != 2)
            {
                printf("Invalid mode. Please choose 1 (Easy) or 2 (Hard).\n");
                continue;
            }
        }
        printf("Choose the board size (3, 5, or 7): ");
        scanf("%d", &size);
        if (size != 3 && size != 5 && size != 7)
        {
            printf("Invalid board size. Please choose 3, 5, or 7.\n");
            continue;
        }

        play_game(size, mode, vs);

        printf("Play again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
        {
            display_score(vs);
            break;
        }
    }
}

void display_score(int game_mode)
{
    game_mode == 1 ? printf("You: %d - Computer: %d\n", user_score, computer_score) : printf("Player 1: %d - Player 2: %d\n", user_score, computer_score);
}

void display_history()
{
    printf("*************************************************************\n");
    printf("*                    Tic Tac Toe History                    *\n");
    printf("*************************************************************\n");
    printf("|    Date    |   Time   |  Player  | Level | Result | Coins |\n");
    printf("|------------|----------|----------|-------|--------|-------|\n");

    for (int i = 0; i < histories.count; i++)
    {
        printf("| %-11s| %-8s | %-8s | %-5s | %-6s | %-5d |\n",
               histories.history[i].datetime,
               histories.history[i].time,
               histories.history[i].username,
               histories.history[i].result,
               "Easy",
               histories.history[i].coins);
    }

    printf("*************************************************************\n");
}
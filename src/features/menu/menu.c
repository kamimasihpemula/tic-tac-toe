#include "../../main.h"
#include "menu.h"
#include "../game/game.h"
#include "../../global.h"
#include "../game/states/save_game.h"
#include "../game/states/load_game.h"
#include "guide/TTC_HowToPlay.h"
#include "../shop/shop.h"

void display_menu()
{
    while (1)
    {
        printf("\n");
        // Menampilkan Tulisa TIC TAC TOE untuk cover
        printf("   .========================================================.\n");
        printf("   ||  _______ _        _______           _______          ||\n");
        printf("   || |__   __(_)      |__   __|         |__   __|         ||\n");
        printf("   ||    | |   _  ___     | | __ _  ___     | | ___   ___  ||\n");
        printf("   ||    | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ ||\n");
        printf("   ||    | |  | | (__     | | (_| | (__     | | (_) |  __/ ||\n");
        printf("   ||    |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| ||\n");
        printf("   '========================================================'\n");
        printf("\n");

        // Menampilkan Menu
        printf("                             .------.\n");
        printf("                             | MENU |\n");
        printf("                             '------'\n");
        printf("\n");
        printf("                       .----------------------.\n");
        printf("                       | 1. Play The Game     |\n");
        printf("                       | 2. History Game      |\n");
        printf("                       | 3. Load Game         |\n");
        printf("                       | 4. Shop              |\n");
        printf("                       | 5. Setting           |\n");
        printf("                       | 6. How To Play?      |\n");
        printf("                       | 7. Exit The Game     |\n");
        printf("                       '----------------------'\n");
        printf("\n");
        printf("   Pilih Menu : ");
        int choice;
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            start_game();
            break;
        case 2:
            display_history();
            break;
        case 3:
            load_game();
            break;
        case 4:
            shop();
            break;
        case 5:
            printf("Fitur sedang dalam pengembangan");
            break;
        case 6:
            guide();
            break;
        case 7:
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
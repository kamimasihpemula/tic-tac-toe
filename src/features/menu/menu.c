#include "../../main.h"
#include "menu.h"
#include "../game/states/save_game.h"
#include "../game/states/load_game.h"
#include "../guide/guide.h"
#include "../shop/shop.h"
#include "../setting/setting.h"

// Clear getchar, scanf, etc
void clear_stream(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        continue;                   // discard extra characters
    }
}

void display_menu()
{
    Histories histories;
    User user;
    Sound sound[6];

    if (load_game(&histories, &user, sound) == 0)
    {
        histories.size = 0;
        histories.user_score = 0;
        histories.computer_score = 0;
        sound[0] = (Sound){.name = "Default", .price = 0, .purchased = "Yes"};
        sound[1] = (Sound){.name = "Acumalaka", .price = 32, .purchased = "No"};
        sound[2] = (Sound){.name = "Doeem", .price = 10, .purchased = "No"};
        sound[3] = (Sound){.name = "Roz", .price = 30, .purchased = "No"};
        sound[4] = (Sound){.name = "Whoossh", .price = 10, .purchased = "No"};
        sound[5] = (Sound){.name = "Wind", .price = 52, .purchased = "No"};
        user.sound.name = sound[0].name;
        user.coins = 100;
    }

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
        printf("                       | 3. Shop              |\n");
        printf("                       | 4. Setting           |\n");
        printf("                       | 5. How To Play?      |\n");
        printf("                       | 6. Exit The Game     |\n");
        printf("                       '----------------------'\n");
        printf("\n");
        printf("   Pilih Menu : ");
        int choice;
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice)
        {
        case 1:
            start_game(&histories, &user, sound);
            break;
        case 2:
            display_history(histories, user);
            break;
        case 3:
            shop(&user, sound, &histories);
            break;
        case 4:
            setting(&user, sound, &histories);
            break;
        case 5:
            guide();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}

void start_game(Histories *data, User *user, Sound sound[6])
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

        play_game(size, mode, vs, data, user, sound);
        display_score(vs, data);

        printf("Play again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y')
            break;
    }
}

void display_score(int game_mode, Histories *data)
{
    game_mode == 1 ? printf("You: %d - Computer: %d\n", data->user_score, data->computer_score) : printf("Player 1: %d - Player 2: %d\n", data->user_score, data->computer_score);
}

void display_history(Histories data, User user)
{
    printf("Your coins: %d\n", user.coins);
    printf("*****************************************************************\n");
    printf("*                         Tic Tac Toe Score                     *\n");
    printf("\t\tYou: %d - Computer: %d\n", data.user_score, data.computer_score);
    printf("*****************************************************************\n");
    printf("*                         Tic Tac Toe History                   *\n");
    printf("*****************************************************************\n");
    printf("| Date       | Time     | Game         | Level | Result | Coins |\n");
    printf("|------------|----------|--------------|-------|--------|-------|\n");
    for (int i = 0; i < data.size; i++)
    {
        printf("| %-10s | %-8s | %-12s | %-5s | %-6s | %-5d |\n", data.history[i].date, data.history[i].time, data.history[i].game, data.history[i].level, data.history[i].result, data.history[i].coins);
    }

    printf("*****************************************************************\n");
    printf("\n Tekan Enter untuk kembali");
    clear_stream();
    getchar();
}
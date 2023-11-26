#include "shop.h"
#include "../../main.h"
#include "../menu/menu.h"
#include "../game/states/save_game.h"

void shop(User *user, Sound sound[6], Histories *histories)
{
    while (1)
    {
        char menu;
        printf("\n");
        printf("   .========================================================.\n");
        printf("   ||  _______ _        _______           _______          ||\n");
        printf("   || |__   __(_)      |__   __|         |__   __|         ||\n");
        printf("   ||    | |   _  ___     | | __ _  ___     | | ___   ___  ||\n");
        printf("   ||    | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ ||\n");
        printf("   ||    | |  | | (__     | | (_| | (__     | | (_) |  __/ ||\n");
        printf("   ||    |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| ||\n");
        printf("   '========================================================'\n\n");

        // Menampilkan Shop
        printf("                             .------.\n");
        printf("                             | SHOP |\n");
        printf("                             '------'\n\n");

        printf("  .------------------------------------------------------------------.\n");
        printf("  | No |              Sound                      | Price | Purchased |\n");
        printf("  |----|-----------------------------------------|-------|-----------|\n");

        for (int i = 0; i < 6; i++)
        {
            printf("  | %d  | %s", i + 1, sound[i].name);
            for (int j = 0; j < 40 - (int)strlen(sound[i].name); j++)
            {
                printf(" ");
            }

            printf("| %d    | %s         |\n", sound[i].price, sound[i].purchased);
        }
        printf("  '------------------------------------------------------------------'\n\n");

        // Menampilan koin saat ini, ketika sudah selesai membeli sound koin ini akan berkurang
        printf("  Koin Anda Saat Ini : %d\n", user->coins);

        buy_sound(user, sound);
        save_game(histories, user, sound);

        // Tampilan saat no sound yang diimputkan benar : "printf("Anda Berhasil Membeli Sound (1-6)\n")"
        // Tampilan saat no sound yang diimputkan salah : "printf("Maaf No Sound Yang Anda Inputkan Salah\n")"
        // printf("Fitur shop saat ini masih dalam proses pengembangan\n");

        printf("  Apakah Anda ingin kembali ke menu? (y/n): ");
        scanf(" %c", &menu);
        if (menu == 'y' || menu == 'Y')
        {
            display_menu();
        }
        else
        {
            continue;
        }
    }
}

void buy_sound(User *user, Sound sound[6])
{
    int no;
    char valid;

    printf("  Masukkan No Sound Yang Ingin Anda Beli : ");
    scanf("%d", &no);

    if (no < 1 || no > 6)
    {
        printf("  Maaf No Sound Yang Anda Inputkan Salah\n");
        return;
    }
    else if (strcmp(sound[no - 1].purchased, "Yes") == 0)
    {
        printf("  Maaf Anda Sudah Membeli Sound Ini\n");
        return;
    }

    printf("  Apakah Anda Yakin Ingin Membeli Sound Ini? (y/t): ");
    scanf(" %c", &valid);

    if (valid == 'y' || valid == 'Y')
    {
        if (user->coins >= sound[no - 1].price)
        {
            user->coins -= sound[no - 1].price;
            printf("  Anda Berhasil Membeli Sound %s\n", sound[no - 1].name);
            sound[no - 1].purchased = "Yes";
        }
        else
        {
            printf("  Maaf Koin Anda Tidak Cukup Untuk Membeli Sound Ini\n");
        }
    }
    else
    {
        printf("  Anda Tidak Jadi Membeli Sound Ini\n");
    }
}
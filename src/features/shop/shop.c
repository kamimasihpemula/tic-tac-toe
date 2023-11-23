#include "shop.h"
#include "../../main.h"
#include "../menu/menu.h"
#include "../../global.h"

void shop()
{
    while (1)
    {
        int menu;
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

        printf("  .----------------------------------------------------------------.\n");
        printf("  | No |              Sound                    | Price | Purchased |\n");
        printf("  |----|---------------------------------------|-------|-----------|\n");
        printf("  | 1  |             Original                  |  000  |     O     |\n");
        printf("  | 2  |               xxx                     |  000  |     X     |\n");
        printf("  | 3  |               xxx                     |  000  |     X     |\n");
        printf("  | 4  |               xxx                     |  000  |     X     |\n");
        printf("  | 5  |               xxx                     |  000  |     X     |\n");
        printf("  | 6  |               xxx                     |  000  |     X     |\n");
        printf("  '----------------------------------------------------------------'\n\n");

        // Menampilan koin saat ini, ketika sudah selesai membeli sound koin ini akan berkurang
        printf("  Koin Anda Saat Ini : \n");

        // Input no sound
        printf("  Masukkan No Sound Yang Ingin Anda Beli : \n");

        // Tampilan saat berhasil mengimput no sound
        printf("  Apakah Anda Yakin Ingin Membeli Sound Ini? (y/t)\n\n");

        // Tampilan saat no sound yang diimputkan benar : "printf("Anda Berhasil Membeli Sound (1-6)\n")"
        // Tampilan saat no sound yang diimputkan salah : "printf("Maaf No Sound Yang Anda Inputkan Salah\n")"
        printf("Fitur shop saat ini masih dalam proses pengembangan\n");
        printf("Enter 0 to go back\n\n");
        scanf("%d", &menu);
        if (menu == 0)
        {
            display_menu();
        }
        else
        {
            printf("Invalid input.\n");
            continue;
        }
    }
}
#include "../../main.h"
#include "fitur_menu.h"
#include "menu.h"
#include "guide/TTC_HowToPlay.h"
#include "../shop/shop.h"
#include "../../global.h"

void display_mainmenu()
{
    while (1)
    {
        int menu;
        printf("\n");
        //Menampilkan Tulisa TIC TAC TOE untuk cover
        printf("   .========================================================.\n");
        printf("   ||  _______ _        _______           _______          ||\n");
        printf("   || |__   __(_)      |__   __|         |__   __|         ||\n");
        printf("   ||    | |   _  ___     | | __ _  ___     | | ___   ___  ||\n");
        printf("   ||    | |  | |/ __|    | |/ _` |/ __|    | |/ _ \\ / _ \\ ||\n");
        printf("   ||    | |  | | (__     | | (_| | (__     | | (_) |  __/ ||\n");
        printf("   ||    |_|  |_|\\___|    |_|\\__,_|\\___|    |_|\\___/ \\___| ||\n");
        printf("   '========================================================'\n");
        printf("\n");

        //Menampilkan Menu
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
        scanf("%d", &menu);
        printf("\n\n");
        if (menu == 1)
        {
            display_menu();
        } else if (menu == 4)
        {
            shop();
        } else if (menu == 6)
        {
            guide();
        } else if (menu == 7)
        {
            exit(0);
        } else if (menu != 1 && menu != 4 && menu <= 5)
        {
            printf("Fitur sedang dalam pengembangan");
        } else
        {
            printf("Invalid input.\n");
            continue;
        }
             
        
        
        
    }
}    
#include "TTC_HowToPlay.h"
#include "../../../main.h"
#include "../Fitur_Menu.h"
#include "../../../global.h"

void guide(){
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

        //Menampilkan Fitur How To Play?
        printf("                           .--------------. \n");
        printf("                           | HOW TO PLAY? | \n");
        printf("                           '--------------'\n");
        printf("   .-------------------------------------------------------.\n");
        printf("   | 1. Pertama,Pemain dengan simbol X akan memulai        |\n");
        printf("   |    permainan                                          |\n");
        printf("   | 2. Setiap kesempatan, pemain diberi waktu 10 detik    |\n");
        printf("   | 3. Lalu, pemain kedua akan melanjutkan dengan O       |\n");
        printf("   | 4. Begitu seterusnya hingga salah satu pemain telah   |\n");
        printf("   |    menggambar tiga simbol dalam satu deret, entah     |\n");
        printf("   |    secara horizontal, vertical maupun diagonal        |\n");
        printf("   | 5. Player dikatakan menang ketika bidaknya membentuk  |\n");
        printf("   |    deret untuk 3x3 : 3 deret  bidak, untuk 5x5 : 4    |\n");
        printf("   |    deret bidak, untuk 7x7 : 5 deret bidak             |\n");
        printf("   '-------------------------------------------------------'\n\n");

        printf("Enter 0 to go back\n\n");
        scanf("%d", &menu);
        if (menu == 0)
        {
             display_mainmenu();
        }   else
        {
            printf("Invalid input.\n");
            continue;
        }
    }
}


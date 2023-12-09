#include "guide.h"
#include "../menu/menu.h"

void guide()
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

        //Menampilkan Fitur How To Play?
    printf("                          .--------------. \n");
    printf("                          | HOW TO PLAY? | \n");
    printf("                          '--------------' \n");
    printf("   .-----------------------------------------------------------.\n");
    printf("   |                       *Single Player*                     |\n");
    printf("   |                                                           |\n");
    printf("   | 1. Pemain akan diberikan 2 pilihan tingkat kesulitan      |\n");
    printf("   |    permainan yaitu 1-easy dan 2-hard. Pemain bisa         |\n");
    printf("   |    menginputkan “1” lalu enter pada keyboard jika ingin   |\n");
    printf("   |    bermain di tingkat kesulitan easy,  pemain juga bisa   |\n");
    printf("   |    menginputkan “2” lalu enter pada keyboard jika ingin   |\n");
    printf("   |    bermain di tingkat kesulitan hard.                     |\n");
    printf("   | 2. Selanjutnya, pemain akan diberikan 3 pilihan ukuran    |\n");
    printf("   |    papan, yang terdiri dari 3,5 atau 7. Pemain bisa       |\n");
    printf("   |    menginputkan “3” lalu tekan enter pada keyboard jika   |\n");
    printf("   |    pemain ingin bermain pada papan 3 x 3. Jika pemain     |\n");
    printf("   |    ingin bermain di papan 5 x 5, pemain bisa menginputkan |\n");
    printf("   |    “5” lalu tekan enter pada keyboard. Pilihan terakhir,  |\n");
    printf("   |    pemain bisa menginputkan “7” bila pemain ingin bermain |\n");
    printf("   |    pada papan 7 x 7.                                      |\n");
    printf("   | 3. Setelah memilih ukuran papan, pemain akan melihat      |\n");
    printf("   |    sebuah papan yang kosong. Lalu akan ada tulisan “Enter |\n");
    printf("   |    row (1-x) : “ disini pemain dapat menginputkan simbol  |\n");
    printf("   |    yang ingin ditaruh di baris ke berapa, pemain dapat    |\n");
    printf("   |    menginputkan 1 sampai dengan batas ukuran papan. Lalu  |\n");
    printf("   |    tekan enter.                                           |\n");
    printf("   | 4. Selanjutnya akan muncul tulisan ‘Enter column (1-x) ; “|\n");
    printf("   |    disini pemain diminta untuk menginputkan simbol pada   |\n");
    printf("   |    kolom ke berapa,  pemain dapat menginputkan dari kolom |\n");
    printf("   |    1 sampai dengan batas ukuran papan. Lalu tekan enter.  |\n");
    printf("   | 5. Berikutnya, akan muncul tampilan papan berisi simbol X |\n");
    printf("   |    yang berada di tempat  pemain tentukan. Serta simbol O |\n");
    printf("   |    dari computer.                                         |\n");
    printf("   | 6. Ulangi langkah 4 sampai 5, hingga pemain menang ataupun|\n");
    printf("   |    kalah.                                                 |\n");
    printf("   '-----------------------------------------------------------'\n\n");
    printf("   .-----------------------------------------------------------.\n");
    printf("   |                        *Multiplayer*                      |\n");
    printf("   |                                                           |\n");
    printf("   | 1. Pertama-tama, pemain akan diberikan 3 pilihan ukuran   |\n");
    printf("   |    papan, yang terdiri dari 3,5 atau 7. Pemain bisa       |\n");
    printf("   |    menginputkan “3” lalu tekan enter pada keyboard jika   |\n");
    printf("   |    pemain ingin bermain pada papan 3 x 3. Jika pemain     |\n");
    printf("   |    ingin bermain di papan 5 x 5, pemain bisa menginputkan |\n");
    printf("   |    “5” lalu tekan enter pada keyboard. Pilihan terakhir,  |\n");
    printf("   |    pemain bisa menginputkan “7” bila pemain ingin bermain |\n");
    printf("   |    pada papan 7 x 7.                                      |\n");
    printf("   | 2. Setelah memilih ukuran papan, pemain 1 akan melihat    |\n");
    printf("   |    sebuah papan yang kosong. Lalu akan ada tulisan “Enter |\n");
    printf("   |    row (1-x) : “ disini pemain 1 dapat menginputkan simbol|\n");
    printf("   |    yang ingin ditaruh di baris ke berapa, pemain 1 dapat  |\n");
    printf("   |    menginputkan 1 sampai dengan batas ukuran papan. Lalu  |\n");
    printf("   |    tekan enter.                                           |\n");
    printf("   | 3. Selanjutnya akan muncul tulisan ‘Enter column (1-x) ; “|\n");
    printf("   |    disini pemain 1 diminta untuk menginputkan simbol pada |\n");
    printf("   |    kolom ke berapa,  pemain 1 dapat menginputkan dari     |\n");
    printf("   |    kolom 1 sampai dengan batas ukuran papan. Lalu tekan   |\n");
    printf("   |    enter.                                                 |\n");
    printf("   | 4. Untuk giliran Pemain 2 dapat mengikuti langkah 2-3.    |\n");
    printf("   | 5. Ulangi langkah 2-4 , hingga salah satu dari kedua      |\n");
    printf("   |    pemain menang.                                         |\n");
    printf("   '-----------------------------------------------------------'\n\n");

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

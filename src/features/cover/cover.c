#include "../../main.h"
#include "cover.h"
#include "../menu/menu.h"

void display_cover(){
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
    printf("               .---------------------------------.\n");
    printf("               | M  a  s  i  h  P  e  m  u  l  a |\n");
    printf("               '---------------------------------'\n");
    printf("\n");

    //Menampilkan pembuat game
    printf("                 Made by :\n");
    printf("                 1. 231524064 / Yahya Alfon Sinaga (Leader)\n");
	printf("                 2. 231524050 / Mohammad Amadeus Andika Fadhil\n");
	printf("                 3. 231524054 / Muhammad Gianluigi Julian\n");
    printf("\n");

    //Klik enter untuk lanjut 
    printf("   Klik Enter Untuk Lanjut\n\n");
    scanf("%c");
    display_menu();
}

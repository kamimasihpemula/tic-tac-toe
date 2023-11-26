#include "setting.h"
#include "../../main.h"
#include "../menu/menu.h"
#include "../game/states/save_game.h"

void setting(User *user, Sound sound[6], Histories *histories)
{
    while (1)
    {
        printf("\n");
        printf("  .------------------------------------------------------.\n");
        printf("  | No |              Sound                      | Used  |\n");
        printf("  |----|-----------------------------------------|-------|\n");

        for (int i = 0; i < 6; i++)
        {
            // check if sound is purchased
            if (strcmp(sound[i].purchased, "Yes") == 0)
            {
                printf("  | %d  | %-40s | %s    |\n", i + 1, sound[i].name, strcmp(user->sound.name, sound[i].name) == 0 ? "Yes" : "No");
            }
        }
        printf("  '------------------------------------------------------'\n\n");

        set_sound(user, sound);

        save_game(histories, user, sound);

        printf("  Apakah Anda ingin kembali ke menu? (y/n): ");
        char menu;
        scanf(" %c", &menu);
        if (menu == 'y' || menu == 'Y')
        {
            display_menu();
        }
        else if (menu == 'n' || menu == 'N')
        {
            continue;
        }
        else
        {
            printf("  Maaf Inputan Anda Salah\n");
            continue;
        }
    }
}

void set_sound(User *user, Sound sound[6])
{
    int sound_number;
    printf("  Masukkan nomor sound yang ingin digunakan: ");
    scanf("%d", &sound_number);
    if (sound_number > 0 && sound_number < 7)
    {
        user->sound = sound[sound_number - 1];
        printf("  Sound berhasil diubah\n");
    }
    else
    {
        printf("  Maaf inputan Anda salah\n");
    }
}
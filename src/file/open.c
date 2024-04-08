/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** open_file.c
*/

#include "../include/my.h"

sfTexture *open_file(all_t *all)
{
    sfTexture *opener;

    opener = sfTexture_createFromFile("screenshot.jpg", NULL);
    all->new_zon = sfSprite_create();
    sfSprite_setTexture(all->new_zon, opener, sfFalse);
    sfSprite_setScale(all->new_zon, (sfVector2f){1, 1});
    sfRenderWindow_drawSprite(all->wiw, all->new_zon, NULL);
    return 0;
}

void if_click_open(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 132 && mouse.x <= 198) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            open_file(all);
        }
    }
}

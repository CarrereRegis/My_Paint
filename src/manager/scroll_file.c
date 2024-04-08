/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** scroll.c
*/

#include "../include/my.h"

void if_click_file(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 0 && mouse.x <= 66) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            all->file_scroll = !all->file_scroll;
        }
    }
}

void display_file(all_t *all)
{
    if (all->file_scroll == true) {
        sfRenderWindow_drawSprite(all->wiw, all->file_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->save_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->help_zon->sprite, NULL);
    }
}

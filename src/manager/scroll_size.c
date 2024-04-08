/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** scroll_size.c
*/

#include "../include/my.h"

void if_click_size(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1849 && mouse.x <= 1920) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            all->size_scroll = !all->size_scroll;
        }
    }
}

void display_size(all_t *all)
{
    if (all->size_scroll == true) {
        sfRenderWindow_drawSprite(all->wiw, all->plus_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->minus_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->circle_zon->sprite, NULL);
    }
}

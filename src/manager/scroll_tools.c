/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** scroll_tools.c
*/

#include "../include/my.h"

void if_click_tools(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1783 && mouse.x <= 1849) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            all->tool_scroll = !all->tool_scroll;
        }
    }
}

void display_tools(all_t *all)
{
    if (all->tool_scroll == true) {
        sfRenderWindow_drawSprite(all->wiw, all->eraser_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->pen_zon->sprite, NULL);
        sfRenderWindow_drawSprite(all->wiw, all->bucket_zon->sprite, NULL);
    }
}

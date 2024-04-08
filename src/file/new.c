/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** new_file.c
*/

#include "../../include/my.h"

void new(paint_t *paint, all_t *all)
{
    sfRenderWindow_drawSprite(all->wiw, all->paint_zon, NULL);
    sfVertexArray_clear(paint->vertex);
}

void if_click_new(all_t *all, paint_t *paint)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1723 && mouse.x <= 1789) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            new(paint, all);
        }
    }
}

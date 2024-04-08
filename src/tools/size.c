/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** size.c
*/

#include "../include/my.h"

void if_click_plus(all_t *all, paint_t *paint)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1850 && mouse.x <= 1920) &&
        (mouse.y >= 132 && mouse.y <= 198)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            update_pixel_size(paint, +5);
        }
    }
}

void if_click_minus(all_t *all, paint_t *paint)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1850 && mouse.x <= 1920) &&
        (mouse.y >= 66 && mouse.y <= 132)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            update_pixel_size(paint, -5);
        }
    }
}

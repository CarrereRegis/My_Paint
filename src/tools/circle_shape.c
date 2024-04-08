/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** circle_shape.c
*/

#include "../include/my.h"

void add_pixel_if_inside_circle(paint_t *paint, int i, int j, float radius)
{
    if (i * i + j * j <= radius * radius) {
        paint->pixal.position.x = paint->pos_mouse.x + i;
        paint->pixal.position.y = paint->pos_mouse.y + j;
        sfVertexArray_append(paint->vertex, paint->pixal);
    }
}

void circle_eraser(paint_t *paint, sfVector2f pos_mouse)
{
    float radius;
    int x_check = (pos_mouse.x >= 1789 && pos_mouse.x <= 1855);
    int y_check = (pos_mouse.y >= 0 && pos_mouse.y <= 66);

    paint->pixal.color = (x_check && y_check) ? sfTransparent : sfWhite;
    radius = (float)paint->pixel / 2.0f;
    for (int i = -paint->pixel; i <= paint->pixel; i++) {
        for (int j = -paint->pixel; j <= paint->pixel; j++) {
            add_pixel_if_inside_circle(paint, i, j, radius);
        }
    }
}

void circle_eraser_condition(all_t *all)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        all->pen_pressed = false;
        all->erase_pressed = false;
        all->circle_eraser = true;
    }
}

void if_click_circle(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1850 && mouse.x <= 1920) &&
        (mouse.y >= 198 && mouse.y <= 268)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            circle_eraser_condition(all);
        }
        if (all->event.type == sfEvtMouseButtonReleased)
            all->circle_eraser = false;
    }
}

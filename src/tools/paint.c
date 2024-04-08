/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** paint.c
*/

#include "../../include/struct.h"

void line_draw(paint_t *paint, sfVector2f pos_mouse)
{
    sfVertex pixel;
    int x_check = (pos_mouse.x >= 1789 && pos_mouse.x <= 1855);
    int y_check = (pos_mouse.y >= 0 && pos_mouse.y <= 66);

    pixel.color = (x_check && y_check) ? sfTransparent : sfBlack;
    for (int i = 0; i < paint->pixel; i++) {
        pixel.position.x = pos_mouse.x + i * !x_check;
        for (int j = 0; j < paint->pixel; j++) {
            pixel.position.y = pos_mouse.y + j * !y_check;
            sfVertexArray_append(paint->vertex, pixel);
        }
    }
}

void pen_condition(all_t *all)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        all->erase_pressed = false;
        all->pen_pressed = true;
    }
}

void if_click1(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 1595 && mouse.x <= 1661) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            pen_condition(all);
        }
    }
}

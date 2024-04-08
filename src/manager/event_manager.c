/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** event_manager.c
*/

#include "../../include/my.h"

void closing(all_t *all)
{
    if ((all->event.type) == sfEvtClosed) {
        sfRenderWindow_close(all->wiw);
    }
}

void closing_help_wiw(all_t *all)
{
    if ((all->event.type) == sfEvtClosed) {
        sfRenderWindow_close(all->help_wiw);
    }
}

void paint_condition(paint_t *paint, all_t *all)
{
    if (all->pen_pressed == true && all->erase_pressed == false) {
                line_draw(paint, paint->pos_mouse);
    }
    if (all->erase_pressed == true && all->pen_pressed == false) {
                line_eraser(paint, paint->pos_mouse);
    }
    if (all->pen_pressed == false && all->erase_pressed == false &&
    all->circle_eraser == true) {
                circle_eraser(paint, paint->pos_mouse);
    }
}

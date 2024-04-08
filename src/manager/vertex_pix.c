/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** vertex_pix.c
*/

#include "../include/my.h"

void set_vertex(paint_t *paint)
{
    paint->vertex = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(paint->vertex, sfLineStrip);
    return;
}

void set_pixel_draw(all_t *all, paint_t *paint)
{
    paint->mouse = SMPRW(all->wiw);
    paint->pos_mouse = SRWPTC(all->wiw, paint->mouse, NULL);
}

void update_pixel_size(paint_t *paint, int delta)
{
    paint->pixel = (paint->pixel + delta > 0) ? paint->pixel + delta : 1;
}

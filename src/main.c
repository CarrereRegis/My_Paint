/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** main.c
*/

#include "../include/my.h"


void if_click(all_t *all, paint_t *paint)
{
    if_click1(all);
    if_click2(all);
    if_click_help(all);
    if_click_save(all);
    if_click_open(all);
    if_click_new(all, paint);
    if_click_circle(all);
    if_click_file(all);
    if_click_tools(all);
    if_click_size(all);
}

void loop(all_t *all, paint_t *paint)
{
    while (sfRenderWindow_isOpen(all->wiw)) {
        while (sfRenderWindow_pollEvent(all->wiw, &(all->event))) {
            closing(all);
            set_pixel_draw(all, paint);
            if_click_plus(all, paint);
            if_click_minus(all, paint);
        }
        if_click(all, paint);
        paint_condition(paint, all);
        affichage(all, paint);
        sfRenderWindow_display(all->wiw);
    }
}

int main(void)
{
    all_t *all = malloc(sizeof(all_t));
    paint_t *paint = malloc(sizeof(paint_t));

    all->pen_pressed = false;
    all->erase_pressed = false;
    all->circle_eraser = false;
    all->file_scroll = false;
    all->size_scroll = false;
    all->tool_scroll = false;
    all->screenshot_saved = true;
    paint->pixel = 10;
    set_image(all);
    set_tools(all);
    set_menu(all);
    set_vertex(paint);
    loop(all, paint);
    destroy_sprite(all);
    free(all);
    return 0;
}

/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include "struct.h"

    #define SRWPTC sfRenderWindow_mapPixelToCoords
    #define SMPRW  sfMouse_getPositionRenderWindow
    #define STCFF  sfTexture_createFromFile
    #define SRWC   sfRenderWindow_create
    #define SRWGS  sfRenderWindow_getSize

void closing(all_t *all);
void set_menu(all_t *all);
void set_image(all_t *all);
void set_param(all_t *all);
void set_tools(all_t *all);
void if_click1(all_t *all);
void if_click2(all_t *all);
void display_file(all_t *all);
void display_size(all_t *all);
void display_tools(all_t *all);
void if_click_file(all_t *all);
void if_click_open(all_t *all);
void if_click_save(all_t *all);
void if_click_help(all_t *all);
void if_click_size(all_t *all);
void if_click_tools(all_t *all);
void set_vertex(paint_t *paint);
void destroy_sprite(all_t *all);
void if_click_circle(all_t *all);
void closing_help_wiw(all_t *all);
void destroy_button(button_t *button);
void affichage(all_t *all, paint_t *paint);
void if_click_new(all_t *all, paint_t *paint);
void if_click_plus(all_t *all, paint_t *paint);
void if_click_minus(all_t *all, paint_t *paint);
void set_pixel_draw(all_t *all, paint_t *paint);
void paint_condition(paint_t *paint, all_t *all);
void update_pixel_size(paint_t *paint, int delta);
void line_draw(paint_t *paint, sfVector2f pos_mouse);
void line_eraser(paint_t *paint, sfVector2f pos_mouse);
void circle_eraser(paint_t *paint, sfVector2f pos_mouse);
void create(const char *, sfVector2f, sfVector2f, button_t **);
void set_button_position(button_t *button, sfVector2f position);

#endif

/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** struct.h
*/

#include "my.h"

#ifndef STRUCT
    #define STRUCT

typedef struct paint_s {
    sfVertexArray *vertex;
    sfVertex pixal;
    sfVector2i mouse;
    sfVector2f pos_mouse;
    int pixel;
} paint_t;

typedef struct button_s {
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f position;
    sfVector2f size;
} button_t;

typedef struct all_s {
    sfRenderWindow *wiw;
    sfRenderWindow *help_wiw;
    sfRenderWindow *new;
    sfEvent event;
    sfTexture *saver;
    sfTexture *work_text;
    sfTexture *button_text;
    sfImage *screenshot;
    sfSprite *new_zon;
    sfSprite *paint_zon;
    sfSprite *tool_zon;
    sfSprite *help_win;
    button_t *save_zon;
    button_t *file_zon;
    button_t *help_zon;
    button_t *eraser_zon;
    button_t *pen_zon;
    button_t *bucket_zon;
    button_t *plus_zon;
    button_t *minus_zon;
    button_t *circle_zon;
    button_t *tools;
    button_t *settings;
    button_t *size;
    bool screenshot_saved;
    bool pen_pressed;
    bool erase_pressed;
    bool circle_eraser;
    bool file_scroll;
    bool tool_scroll;
    bool size_scroll;
} all_t;

#endif

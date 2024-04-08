/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** image_loader.c
*/

#include "../../include/my.h"

void set_image(all_t *all)
{
    sfVideoMode mode = {1920, 1080, 32};

    all->wiw = sfRenderWindow_create(mode, "Paint", sfResize | sfClose, NULL);
    all->work_text = STCFF("./assets/work_place.jpg", NULL);
    all->button_text = STCFF("./assets/button_font.jpg", NULL);
    all->paint_zon = sfSprite_create();
    all->tool_zon = sfSprite_create();
    sfSprite_setTexture(all->paint_zon, all->work_text, sfTrue);
    sfSprite_setTexture(all->tool_zon, all->button_text, sfTrue);
    sfSprite_setScale(all->paint_zon, (sfVector2f){34, 18});
    sfSprite_setScale(all->tool_zon, (sfVector2f){72, 2.5});
    sfRenderWindow_clear(all->wiw, sfWhite);
}

void set_tools(all_t *all)
{
    create("./assets/eraser.jpg", (sfVector2f){1657, 0}, (sfVector2f){1, 1},
    &all->eraser_zon);
    create("./assets/pen.jpg", (sfVector2f){1595, 0}, (sfVector2f){1, 1},
    &all->pen_zon);
    create("./assets/bucket.jpg", (sfVector2f){1723, 0}, (sfVector2f){1, 1},
    &all->bucket_zon);
    create("./assets/file.jpg", (sfVector2f){125, 0}, (sfVector2f){1, 1},
    &all->file_zon);
    create("./assets/save.jpg", (sfVector2f){66, 0}, (sfVector2f){1, 1},
    &all->save_zon);
    create("./assets/help.jpg", (sfVector2f){191, 0}, (sfVector2f){1, 1},
    &all->help_zon);
    create("./assets/minus_button.jpg", (sfVector2f){1850, 66},
    (sfVector2f){1, 1}, &all->plus_zon);
    create("./assets/plus_button.jpg", (sfVector2f){1850, 132},
    (sfVector2f){1, 1}, &all->minus_zon);
    create("./assets/circle_shape.jpg", (sfVector2f){1850, 198},
    (sfVector2f){1, 1}, &all->circle_zon);
}

void set_menu(all_t *all)
{
    create("./assets/settings.jpg", (sfVector2f){0, -5}, (sfVector2f){1, 1},
    &all->settings);
    create("./assets/size.jpg", (sfVector2f){1852, -5}, (sfVector2f){1, 1},
    &all->size);
    create("./assets/tools.jpg", (sfVector2f){1783, -5}, (sfVector2f){1, 1},
    &all->tools);
}

void affichage(all_t *all, paint_t *paint)
{
    sfRenderWindow_drawVertexArray(all->wiw, paint->vertex, NULL);
    sfRenderWindow_drawSprite(all->wiw, all->tool_zon, NULL);
    display_file(all);
    display_tools(all);
    display_size(all);
    sfRenderWindow_drawSprite(all->wiw, all->tools->sprite, NULL);
    sfRenderWindow_drawSprite(all->wiw, all->settings->sprite, NULL);
    sfRenderWindow_drawSprite(all->wiw, all->size->sprite, NULL);
}

void destroy_sprite(all_t *all)
{
    sfRenderWindow_destroy(all->wiw);
    sfSprite_destroy(all->tool_zon);
    sfSprite_destroy(all->paint_zon);
    destroy_button(all->save_zon);
    destroy_button(all->file_zon);
    destroy_button(all->help_zon);
    destroy_button(all->eraser_zon);
    destroy_button(all->pen_zon);
    destroy_button(all->bucket_zon);
    destroy_button(all->plus_zon);
    destroy_button(all->minus_zon);
    destroy_button(all->circle_zon);
    destroy_button(all->settings);
    destroy_button(all->tools);
    destroy_button(all->size);
}

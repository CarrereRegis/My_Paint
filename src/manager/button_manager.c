/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** button.c
*/

#include "../../include/my.h"

void create
(const char *filename, sfVector2f position, sfVector2f size, button_t **all)
{
    if (filename == NULL || *all == NULL)
        return;
    *all = malloc(sizeof(button_t));
    if (*all == NULL) {
        return;
    }
    (*all)->sprite = sfSprite_create();
    (*all)->texture = sfTexture_createFromFile(filename, NULL);
    (*all)->position = position;
    (*all)->size = size;
    sfSprite_setTexture((*all)->sprite, (*all)->texture, sfTrue);
    sfSprite_setPosition((*all)->sprite, (*all)->position);
    sfSprite_setScale((*all)->sprite, (*all)->size);
}

void set_button_position(button_t *button, sfVector2f position)
{
    button->position = position;
    sfSprite_setPosition(button->sprite, position);
}

void destroy_button(button_t *button)
{
    sfTexture_destroy(button->texture);
    sfSprite_destroy(button->sprite);
    free(button);
}

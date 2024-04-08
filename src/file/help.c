/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** help.c
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../include/my.h"

static const char help[] =
"Bienvenue dans My_paint, ceci est une reprise du logiciel "
"Paint disponible sous windows.\n"
"\nInstructions : \n"
"1. Si vous voulez dessiner cliquer sur l'icone de crayon"
"et maintener la souris pour pouvoir dessiner.\n"
"2. Si vous voulez effacer cliquer sur la gomme.\n"
"3. Et si vous voulez sauvegarder cliquer sur le disque dur.\n"
"\nUser: armanddufresne";

void initialize_window(all_t *all)
{
    sfTexture *help_text;
    sfVideoMode mode = {1920, 1080, 32};

    all->help_wiw = SRWC(mode, "Paint", sfResize | sfClose, NULL);
    help_text = sfTexture_createFromFile("./assets/work_place.jpg", NULL);
    all->help_win = sfSprite_create();
    sfSprite_setTexture(all->help_win, help_text, sfTrue);
    sfSprite_setScale(all->help_win, (sfVector2f){34, 18});
}

void draw_instructions(all_t *all)
{
    sfFont* font = sfFont_createFromFile("./assets/arial.otf");
    sfText* text = sfText_create();

    sfText_setString(text, help);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setPosition(text, (sfVector2f){50, 50});
    sfText_setFillColor(text, sfBlack);
    sfRenderWindow_clear(all->help_wiw, sfWhite);
    sfRenderWindow_drawText(all->help_wiw, text, NULL);
    sfRenderWindow_display(all->help_wiw);
    sfText_destroy(text);
    sfFont_destroy(font);
}

void show_instructions(all_t *all)
{
    initialize_window(all);
    while (sfRenderWindow_isOpen(all->help_wiw)) {
        while (sfRenderWindow_pollEvent(all->help_wiw, &(all->event))) {
            closing_help_wiw(all);
        }
        draw_instructions(all);
    }
    sfRenderWindow_destroy(all->help_wiw);
}

void if_click_help(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if ((mouse.x >= 191 && mouse.x <= 257) &&
        (mouse.y >= 0 && mouse.y <= 66)) {
        if ((all->event.type) == sfEvtMouseButtonPressed) {
            show_instructions(all);
        }
    }
}

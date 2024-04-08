/*
** EPITECH PROJECT, 2023
** B-MUL-200-BDX-2-1-mypaint-regis.carrere
** File description:
** save.c
*/

#include "../../include/my.h"

void capture(all_t *all)
{
    all->saver = sfTexture_create(SRWGS(all->wiw).x, SRWGS(all->wiw).y);
    sfTexture_updateFromRenderWindow(all->saver, all->wiw, 0, 0);
}

void save(all_t *all, const char *filename)
{
    capture(all);
    all->screenshot = sfTexture_copyToImage(all->saver);
    sfImage_saveToFile(all->screenshot, filename);
    sfImage_destroy(all->screenshot);
    sfTexture_destroy(all->saver);
}

void if_click_save(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->wiw);

    if (mouse.x >= 66 && mouse.x <= 132 &&
        mouse.y >= 0 && mouse.y <= 66) {
        if (all->event.type == sfEvtMouseButtonPressed) {
            save(all, "screenshot.jpg");
        }
    }
}

/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** intro
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include <stdio.h>

int get_events(sfEvent *event, sfRenderWindow *window)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->key.code == sfKeySpace)
            return (1);
    }
    return (0);
}

int change_color(sfRectangleShape *rect, sfClock *clock)
{
    sfColor color = sfRectangleShape_getFillColor(rect);

    printf("Color : %d\n", color.r);
    if (sfTime_asSeconds(sfClock_getElapsedTime(clock)) >= 0.1) {
        color.a--;
        sfRectangleShape_setFillColor(rect, color);
        sfClock_restart(clock);
    }
    if (color.a == 0)
        return (1);
    return (0);
}

void display_intro(sfRenderWindow *window)
{
    sfRectangleShape *fade = sfRectangleShape_create();
    sfEvent event;
    int quit = 0;
    sfClock *clock = sfClock_create();
    sfTexture *texture = sfTexture_createFromFile("./assets/beginning.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfRectangleShape_setFillColor(fade, sfBlack);
    sfRectangleShape_setSize(fade, (sfVector2f){1920, 1080});
    sfSprite_setTexture(sprite, texture, sfFalse);
    while (sfRenderWindow_isOpen(window) && quit != 1) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        quit += change_color(fade, clock);
        sfRenderWindow_drawRectangleShape(window, fade, NULL);
        quit += get_events(&event, window);
        sfRenderWindow_display(window);
    }
}

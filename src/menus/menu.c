/*
** EPITECH PROJECT, 2019
** Tower Defense
** File description:
** Menu file
*/

#include "prototype.h"

void disp_menu(scene_t *scene)
{
    int i = 0;

    sfRenderWindow_clear(scene->window, sfBlack);
    sfRenderWindow_drawSprite(scene->window, scene->spr_back, NULL);
    while (scene->button[i] != NULL) {
        sfRenderWindow_drawRectangleShape(scene->window,
                                scene->button[i]->but, NULL);
        sfRenderWindow_drawText(scene->window, scene->button[i]->txt, NULL);
        i++;
    }
    sfRenderWindow_display(scene->window);
}

void screenevent(sfEvent *event, 
        scene_t *scene, int *gamemode, option_t *option)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(scene->window);

    if (event->type == sfEvtMouseButtonPressed)
        check_all_button(scene->button, scene);
    if (event->type == sfEvtMouseButtonReleased) {
        if (button_is_clicked(scene->button[0]->but, mouse) == 0)
            (*gamemode) = 1;
        if (button_is_clicked(scene->button[1]->but, mouse) == 0)
            (*gamemode) = 3;
        if (button_is_clicked(scene->button[2]->but, mouse) == 0)
            option_function(scene, option);
        reboot(scene->button);
    }
    if (event->type == sfEvtClosed) {
        *gamemode = 3;
    }
}

int init_menu_scene(scene_t *scene)
{
    char *path_back = "assets/textures/menu.jpg";

    scene->perso = NULL;
    scene->ennemi = NULL;
    scene->button = malloc(sizeof(but_s) * 4);
    if (scene->button == NULL)
        return (84);
    scene->button[0] = malloc(sizeof(but_s));
    scene->button[1] = malloc(sizeof(but_s));
    scene->button[2] = malloc(sizeof(but_s));
    scene->button[3] = NULL;
    if (scene->button[0] == NULL || scene->button[1] == NULL)
        return (84);
    scene->text_back = sfTexture_createFromFile(path_back, NULL);
    scene->spr_back = sfSprite_create();
    sfSprite_setTexture(scene->spr_back, scene->text_back, sfFalse);
    init_start_button(scene->button[0]);
    init_end_button(scene->button[1]);
    init_option_button(scene->button[2]);
    return (0);
}

void destroy_menu(scene_t *scene, int *gamemode)
{
    int i = 0;

    while (scene->button[i] != NULL) {
        sfRectangleShape_destroy(scene->button[i]->but);
        free(scene->button[i]);
        i++;
    }
    free(scene->button);
    if (*gamemode == 3) {
        sfRenderWindow_close(scene->window);
    }
}

int mainscreen(int *gamemode, scene_t *scene, option_t *option)
{
    sfEvent click;
    int a = 0;

    scene->if_sound = 0;
    init_music(scene);
        sfMusic_play(scene->music->sound);
    *gamemode = init_menu_scene(scene);
    if (*gamemode == 84)
        return (84);
    sfMusic_setLoop(scene->music->sound, sfTrue);
    while (sfRenderWindow_isOpen(scene->window) && *gamemode == 0) {
        if (scene->if_sound == 1)
            sfMusic_stop(scene->music->sound);
        disp_menu(scene);
        button_disp(scene->button, scene);
        while (sfRenderWindow_pollEvent(scene->window, &click))
            screenevent(&click, scene, gamemode, option);
    }
    sfMusic_stop(scene->music->sound);
    destroy_menu(scene, gamemode);
    sfMusic_destroy(scene->music->sound);
    return (0);
}

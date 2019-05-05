/*
** EPITECH PROJECT, 2019
** My RPG
** File description:
** init sound file
*/

#include "prototype.h"

int init_music(scene_t *scene)
{
    scene->music = malloc(sizeof(musics));
    if (scene->music == NULL)
        return (84);
    scene->music->sound = sfMusic_createFromFile(
        "assets/sound/Menu.ogg");
}

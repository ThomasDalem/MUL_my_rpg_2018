/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** Global Free File
*/

#include "prototype.h"

int free_global(scene_t *scene)
{
    free_enn(scene);
    free_perso(scene);
    return (0);
}

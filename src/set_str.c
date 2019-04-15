/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** set_str
*/

#include "prototype.h"

char *set_life_str(scene_t *scene)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "life = ");
    my_strcat(str, int_to_char(scene->perso->stat.max_life));
    return (str);
}

char *set_attack_str(scene_t *scene)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "attack = ");
    my_strcat(str, int_to_char(scene->perso->stat.attack));
    return (str);
}

char *set_defense_str(scene_t *scene)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "defense = ");
    my_strcat(str, int_to_char(scene->perso->stat.defense));
    return (str);
}

char *set_magic_str(scene_t *scene)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "magic = ");
    my_strcat(str, int_to_char(scene->perso->stat.magic));
    return (str);
}
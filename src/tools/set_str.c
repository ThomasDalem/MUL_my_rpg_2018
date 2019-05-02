/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** set_str
*/

#include "prototype.h"

char *set_life_str(obj_t *perso)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "life = ");
    my_strcat(str, int_to_char(perso->stat.life));
    return (str);
}

char *set_attack_str(obj_t *perso)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "attack = ");
    my_strcat(str, int_to_char(perso->stat.attack));
    return (str);
}

char *set_defense_str(obj_t *perso)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "defense = ");
    my_strcat(str, int_to_char(perso->stat.defense));
    return (str);
}

char *set_magic_str(obj_t *perso)
{
    char *str = malloc(sizeof(char) * 20);

    if (str == NULL)
        return (NULL);
    my_strcpy(str, "speed = ");
    my_strcat(str, int_to_char(perso->stat.magic));
    return (str);
}
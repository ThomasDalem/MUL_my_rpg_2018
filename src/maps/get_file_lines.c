/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_file_lines
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include "map.h"

void get_texture(sfTexture **texture, char *filepath)
{
    remove_endline(filepath);
    *texture = sfTexture_createFromFile(filepath, NULL);
    free(filepath);
}

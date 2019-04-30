/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stddef.h>
#include "structures.h"

int button_is_clicked(sfRectangleShape *button, sfVector2i click_position);
void check_all_button(but_s **button, scene_t *scene);
void button_disp(but_s **button, scene_t *scene);
void reboot(but_s **button);

#endif /* !INCLUDE_H_ */

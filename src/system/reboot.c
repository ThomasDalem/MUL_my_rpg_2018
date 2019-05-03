/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** reboot
*/

#include "prototype.h"

void reboot_use_throw(but_s **button)
{
    int i = 0;

    while (button[i] != NULL) {
        button[i]->next[0].is_clicked = 0;
        button[i]->next[1].is_clicked = 0;
        i ++;
    }
}

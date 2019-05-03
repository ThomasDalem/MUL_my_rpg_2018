/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "structures.h"

quest_t *create_quest(void);
void set_quest_name(sfRenderWindow *window, quest_t *quest, char *name);
void display_quest(quest_t *quest, sfRenderWindow *window);
void set_quest_rewards(sfRenderWindow *win, quest_t *quest, int money, int exp);

#endif /* !QUEST_H_ */

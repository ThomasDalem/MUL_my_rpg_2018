/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** quest
*/

#ifndef QUEST_H_
#define QUEST_H_

#include "structures.h"

quest_t *create_quests(sfRenderWindow *window);
quest_t *create_quest(quest_t *next);
void set_quest_name(sfRenderWindow *window, quest_t *quest, char *name);
void display_quest(quest_t *quest, sfRenderWindow *window);
void set_quest_rewards(sfRenderWindow *win, quest_t *quest, int money, int exp);

int check_quest_kill(void *obj, void *check);
int check_quests(scene_t *scene, quest_t *quests);

#endif /* !QUEST_H_ */

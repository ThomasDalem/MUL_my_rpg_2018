/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_phrase
*/

#include "prototype.h"

int copy_into_hi(obj_t *pnj)
{
    FILE *fd = fopen("source/hello", "r");
    size_t n = 0;
    int i = 0;

    pnj->text.hi_phrase = malloc(sizeof(char *) * 6);
    if (pnj->text.hi_phrase == NULL)
        return (84);
    pnj->text.hi_phrase[i] = malloc(sizeof(char) * 4096);
    if (pnj->text.hi_phrase[i] == NULL)
        return (84);
    while (getline(&pnj->text.hi_phrase[i], &n, fd) != -1) {
        i++;
        pnj->text.hi_phrase[i] = malloc(sizeof(char) * 4096);
        if (pnj->text.hi_phrase[i] == NULL)
            return (84);
    }
    return (0);
}

int copy_into_sell(obj_t *pnj)
{
    FILE *fd = fopen("source/sell", "r");
    size_t n = 0;
    int i = 0;

    pnj->text.sell_phrase = malloc(sizeof(char *) * 6);
    if (pnj->text.sell_phrase == NULL)
        return (84);
    pnj->text.sell_phrase[i] = malloc(sizeof(char) * 4096);
    if (pnj->text.sell_phrase[i] == NULL)
        return (84);
    while (getline(&pnj->text.sell_phrase[i], &n, fd) != -1) {
        i++;
        pnj->text.sell_phrase[i] = malloc(sizeof(char) * 4096);
        if (pnj->text.sell_phrase[i] == NULL)
            return (84);
    }
    return (0);
}

int copy_into_by(obj_t *pnj)
{
    FILE *fd = fopen("source/by", "r");
    size_t n = 0;
    int i = 0;

    pnj->text.by_phrase = malloc(sizeof(char *) * 6);
    if (pnj->text.by_phrase == NULL)
        return (84);
    pnj->text.by_phrase[i] = malloc(sizeof(char) * 4096);
    if (pnj->text.by_phrase[i] == NULL)
        return (84);
    while (getline(&pnj->text.by_phrase[i], &n, fd) != -1) {
        i++;
        pnj->text.by_phrase[i] = malloc(sizeof(char) * 4096);
        if (pnj->text.by_phrase[i] == NULL)
            return (84);
    }
    return (0);
}
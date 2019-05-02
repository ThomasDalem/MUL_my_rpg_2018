/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** discuss
*/

#include "prototype.h"

void discuss(scene_t *scene)
{
    int i = 0;
    sfVector2f pos = sfSprite_getPosition(scene->pnj->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->pnj->sprite);

    scene->pnj->discuss = 1;
    pos.x = pos.x - rect.width * 1.5;
    pos.y = pos.y - sfSprite_getGlobalBounds(scene->pnj->text.sprite_bubble)
        height;
    srand(time(NULL));
    i = rand() % 5;
    if (scene->pnj->text.nb_dialog == 0)
        sfText_setString(scene->pnj->text.phrase,
                         scene->pnj->text.hi_phrase[i]);
    if (scene->pnj->text.nb_dialog == 1)
        sfText_setString(scene->pnj->text.phrase,
                         scene->pnj->text.sell_phrase[i]);
    if (scene->pnj->text.nb_dialog == 2)
        sfText_setString(scene->pnj->text.phrase,
                         scene->pnj->text.by_phrase[i]);
    sfText_setFont(scene->pnj->text.phrase, scene->pnj->text.font);
    sfText_setColor(scene->pnj->text.phrase, sfBlack);
    sfText_setCharacterSize(scene->pnj->text.phrase, 40);
    sfText_setPosition(scene->pnj->text.phrase, pos);
    pos.x = pos.x - 50;
    sfSprite_setPosition(scene->pnj->text.sprite_bubble, pos);
}

void orient_pnj(scene_t *scene, sfIntRect *rect_perso)
{
    sfVector2f pos_perso = sfSprite_getPosition(scene->perso->sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(scene->pnj->sprite);
    sfIntRect rect = *rect_perso;
    float x = fabs(pos_perso.x) - fabs(pos_pnj.x);
    float y = fabs(pos_perso.y) - fabs(pos_pnj.y);
    int i = 0;

    talk(scene);
    if (fabs(x) > fabs(y))
        i = 1;
    if (i == 1 && x < 0)
        *rect_perso = scene->pnj->char_left;
    if (i == 1 && x > 0)
        *rect_perso = scene->pnj->char_right;
    if (i == 0 && y < 0)
        *rect_perso = scene->pnj->char_up;
    if (i == 0 && y > 0)
        *rect_perso = scene->pnj->char_down;
    rect_perso->top = rect_perso->top + rect.top;
}

void start_discuss(scene_t *scene)
{
    obj_t *pnj = scene->pnj;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfIntRect rect_pnj = sfSprite_getTextureRect(scene->pnj->sprite);
    sfFloatRect pos_pnj;

    while (scene->pnj != NULL) {
        rect_pnj = sfSprite_getTextureRect(scene->pnj->sprite);
        pos_pnj = sfCircleShape_getGlobalBounds(scene->pnj->detect_zone);
        if (scene->pnj->discuss == 1)
            scene->pnj->text.nb_dialog ++;
        if (scene->pnj->text.nb_dialog == 3) {
            scene->pnj->text.nb_dialog = 0;
            scene->pnj->discuss = 0;
        }
        else if (sfFloatRect_intersects(&pos_perso, &pos_pnj, NULL) == sfTrue) {
            discuss(scene);
            orient_pnj(scene, &rect_pnj);
            sfSprite_setTextureRect(scene->pnj->sprite, rect_pnj);
        }
        scene->pnj = scene->pnj->next;
    }
    scene->pnj = pnj;
}

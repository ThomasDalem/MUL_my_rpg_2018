/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** discuss
*/

#include "prototype.h"

void pos_text(scene_t *scene, sfVector2f pos)
{
    sfText_setFont(scene->map->pnj->text.phrase, scene->map->pnj->text.font);
    sfText_setColor(scene->map->pnj->text.phrase, sfBlack);
    sfText_setCharacterSize(scene->map->pnj->text.phrase, 40);
    sfText_setPosition(scene->map->pnj->text.phrase, pos);
    pos.x = pos.x - 50;
    sfSprite_setPosition(scene->map->pnj->text.sprite_bubble, pos);
}

void discuss(scene_t *scene)
{
    int i = 0;
    sfVector2f pos = sfSprite_getPosition(scene->map->pnj->sprite);
    sfFloatRect rect = sfSprite_getGlobalBounds(scene->map->pnj->sprite);

    scene->map->pnj->discuss = 1;
    pos.x = pos.x - rect.width * 1.5;
    pos.y = pos.y - sfSprite_getGlobalBounds\
        (scene->map->pnj->text.sprite_bubble).height;
    srand(time(NULL));
    i = rand() % 5;
    if (scene->map->pnj->text.nb_dialog == 0)
        sfText_setString(scene->map->pnj->text.phrase,
                            scene->pnj->text.hi_phrase[i]);
    if (scene->map->pnj->text.nb_dialog == 1)
        sfText_setString(scene->map->pnj->text.phrase,
                            scene->pnj->text.sell_phrase[i]);
    if (scene->map->pnj->text.nb_dialog == 2)
        sfText_setString(scene->map->pnj->text.phrase,
                            scene->map->pnj->text.by_phrase[i]);
    pos_text(scene, pos);
}

void orient_pnj(scene_t *scene, sfIntRect *rect_perso)
{
    sfVector2f pos_perso = sfSprite_getPosition(scene->perso->sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(scene->map->pnj->sprite);
    sfIntRect rect = *rect_perso;
    float x = fabs(pos_perso.x) - fabs(pos_pnj.x);
    float y = fabs(pos_perso.y) - fabs(pos_pnj.y);
    int i = 0;

    talk(scene);
    if (fabs(x) > fabs(y))
        i = 1;
    if (i == 1 && x < 0)
        *rect_perso = scene->map->pnj->char_left;
    if (i == 1 && x > 0)
        *rect_perso = scene->map->pnj->char_right;
    if (i == 0 && y < 0)
        *rect_perso = scene->map->pnj->char_up;
    if (i == 0 && y > 0)
        *rect_perso = scene->map->pnj->char_down;
}

void discuss_function(scene_t *scene, sfIntRect rect_pnj)
{
    discuss(scene);
    orient_pnj(scene, &rect_pnj);
    sfSprite_setTextureRect(scene->map->pnj->sprite, rect_pnj);
}

void start_discuss(scene_t *scene)
{
    obj_t *pnj = scene->map->pnj;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfIntRect rect_pnj = sfSprite_getTextureRect(scene->map->pnj->sprite);
    sfFloatRect pos_pnj;

    while (scene->map->pnj != NULL) {
        rect_pnj = sfSprite_getTextureRect(scene->map->pnj->sprite);
        pos_pnj = sfCircleShape_getGlobalBounds(scene->map->pnj->detect_zone);
        if (scene->map->pnj->discuss == 1)
            scene->map->pnj->text.nb_dialog ++;
        if (scene->map->pnj->text.nb_dialog >= 3) {
            scene->map->pnj->text.nb_dialog = 0;
            scene->map->pnj->discuss = 0;
        }
        else if (sfFloatRect_intersects(&pos_perso, &pos_pnj, NULL) == sfTrue)
            discuss_function(scene, rect_pnj);
        scene->map->pnj = scene->map->pnj->next;
    }
    scene->map->pnj = pnj;
}

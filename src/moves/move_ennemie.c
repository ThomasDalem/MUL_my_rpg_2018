/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** move_ennemie
*/

#include "prototype.h"
#include "collisions.h"

void change_direction(obj_t *enemy)
{
    int r = 0;

    r = rand() % 4;
    if (r == 0)
        enemy->move_dir = UP;
    if (r == 1)
        enemy->move_dir = LEFT;
    if (r == 2)
        enemy->move_dir = RIGHT;
    if (r == 3)
        enemy->move_dir = DOWN;
}

void set_good_rect(obj_t *enemy, sfVector2f dist, sfIntRect *rect_perso)
{
    sfVector2f enemy_pos = sfSprite_getPosition(enemy->sprite);
    sfIntRect save = *rect_perso;
    int i = 0;

    if (fabs(dist.x) > fabs(dist.y))
        i = 1;
    else
        i = 0;
    if (i == 1 && dist.x > 0)
        *rect_perso = change_enemy_animation(enemy, LEFT);
    if (i == 1 && dist.x < 0)
        *rect_perso = change_enemy_animation(enemy, RIGHT);
    if (i == 0 && dist.y > 0)
        *rect_perso = change_enemy_animation(enemy, UP);
    if (i == 0 && dist.y < 0)
        *rect_perso = change_enemy_animation(enemy, DOWN);
    rect_perso->left = rect_perso->left + save.left;
}

sfVector2f move_pos(sfVector2f dist, obj_t *en, scene_t *scene)
{
    sfVector2f offset = {0, 0};
    float time = sfTime_asSeconds(sfClock_getElapsedTime(en->move_clock));

    if (dist.x < -1)
        offset.x = 1.0f * time * 60.0f;
    else if (dist.x > 1)
        offset.x = -1.0f * time * 60.0f;
    if (dist.y < -1)
        offset.y = 1.0f * time * 60.0f;
    else if (dist.y > 1)
        offset.y = -1.0f * time * 60.0f;
    return (offset);
}

void follow(scene_t *scene, sfFloatRect enemy_pos, obj_t *enemy)
{
    sfFloatRect player_pos = sfSprite_getGlobalBounds(scene->perso->sprite);
    sfVector2f distance = get_distance(enemy, scene->perso);
    sfVector2f move = move_pos(distance, enemy, scene);
    sfIntRect rect_perso = sfSprite_getTextureRect(enemy->sprite);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(enemy->anim_clock));

    if (time > 0.1)
        set_good_rect(enemy, distance, &rect_perso);
    sfSprite_setTextureRect(enemy->sprite, rect_perso);
    anim(enemy);
    if (!check_enemy_collision(scene, enemy, move)) {
        sfSprite_move(enemy->sprite, move);
        sfCircleShape_move(enemy->detect_zone, move);
    }
}

void move_ennemie(scene_t *scene, map_t *map)
{
    obj_t *enemies = scene->map->enemies;
    sfVector2f enn;
    sfFloatRect pos_zone;
    sfFloatRect pos_enn;
    sfFloatRect pos_perso = sfSprite_getGlobalBounds(scene->perso->sprite);
    float time = 0.0f;

    while (enemies != NULL) {
        move_norm(&pos_zone, &pos_enn, &time, enemies);
        if (sfFloatRect_intersects(&pos_zone, &pos_perso, NULL) == sfTrue)
            follow(scene, pos_enn, enemies);
        else if (time >= 2.0f) {
            change_direction(enemies);
            sfClock_restart(enemies->dir_clock);
        }
        else
            move_enemy(scene, enemies, enemies->move_dir);
        sfClock_restart(enemies->move_clock);
        enemies = enemies->next;
    }
}

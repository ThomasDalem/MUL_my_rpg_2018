/*
** EPITECH PROJECT, 2019
** my_rpg_2018
** File description:
** disp
*/

#include <stdio.h>
#include "prototype.h"
#include "particles.h"
#include "quest.h"

static int recreate_particles(particle_t *particles)
{
    sfColor color;

    if (particles == NULL)
        return (1);
    color = sfCircleShape_getFillColor(particles->circle);
    if (color.a == 0) {
        reset_particles(particles);
        return (1);
    }
    return (0);
}

static void disp_map(sfRenderWindow *window, map_t *map)
{
    particle_t *particles = map->particles;

    for (map_obj_t *obj = map->objects; obj != NULL; obj = obj->next)
        sfRenderWindow_drawSprite(window, obj->sprite, NULL);
    for (obj_t *enemies = map->enemies; enemies != NULL; 
            enemies = enemies->next)
        sfRenderWindow_drawSprite(window, enemies->sprite, NULL);
    for (; particles != NULL; particles = particles->next)
        sfRenderWindow_drawCircleShape(window, particles->circle, NULL);
    recreate_particles(map->particles);
}

void disp_scene(scene_t *scene, quest_t *quest)
{
    obj_t *ennemie = scene->map->enemies;
    obj_t *pnj = scene->pnj;

    sfRenderWindow_clear(scene->window, sfBlack);
    disp_map(scene->window, scene->map);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    while (ennemie) {
        sfRenderWindow_drawSprite(scene->window, ennemie->sprite, NULL);
        ennemie = ennemie->next;
    }
    while (pnj) {
        sfRenderWindow_drawSprite(scene->window, pnj->sprite, NULL);
        if (pnj->discuss == 1) {
            sfRenderWindow_drawSprite(scene->window, pnj->text.sprite_bubble,
                                      NULL);
            sfRenderWindow_drawText(scene->window, pnj->text.phrase, NULL);
        }
        pnj = pnj->next;
    }
    display_quest(quest, scene->window);
    sfRenderWindow_display(scene->window);
}

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

static void disp_npc(sfRenderWindow *window, obj_t *npc)
{
    while (npc) {
        sfRenderWindow_drawSprite(window, npc->sprite, NULL);
        if (npc->discuss && npc->discuss == 1) {
            sfRenderWindow_drawSprite(window, npc->text.sprite_bubble,
                                      NULL);
            sfRenderWindow_drawText(window, npc->text.phrase, NULL);
        }
        npc = npc->next;
    }
}

void disp_scene(scene_t *scene, quest_t *quest)
{
    obj_t *enemies = scene->map->enemies;

    sfRenderWindow_clear(scene->window, sfBlack);
    disp_map(scene->window, scene->map);
    sfRenderWindow_drawSprite(scene->window, scene->perso->sprite, NULL);
    while (enemies) {
        sfRenderWindow_drawSprite(scene->window, enemies->sprite, NULL);
        enemies = enemies->next;
    }
    disp_npc(scene->window, scene->map->pnj);
    display_quest(quest, scene->window);
    sfRenderWindow_display(scene->window);
}

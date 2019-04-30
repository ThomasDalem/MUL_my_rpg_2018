/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_particles
*/

#include <stdlib.h>
#include <SFML/Graphics/CircleShape.h>
#include "structures.h"

void free_particles(particle_t *particles)
{
    particle_t *save = NULL;

    while (particles != NULL) {
        save = particles;
        particles = particles->next;
        sfCircleShape_destroy(save->circle);
        sfClock_destroy(save->move_clock);
        free(save);
    }
}

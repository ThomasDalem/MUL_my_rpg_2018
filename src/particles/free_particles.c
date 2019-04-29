/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_particles
*/

#include <stdlib.h>
#include "structures.h"

void free_particles(particle_t *particles)
{
    particle_t *save = NULL;

    while (particles) {
        save = particles;
        particles = particles->next;
        free(save);
    }
}

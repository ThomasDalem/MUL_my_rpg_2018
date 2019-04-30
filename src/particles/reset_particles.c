/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** reset_particles
*/

#include <SFML/Graphics/CircleShape.h>
#include <stdlib.h>
#include "particles.h"

static void reset_particle(particle_t *particle)
{
    int direction = (rand() % 2 == 1) ? -1 : 1;
    sfVector2f velocity = {rand() % 4 * direction, (rand() % 4) * -1};
    sfVector2f pos = particle->begin_pos;
    sfVector2f spawn_pos = {pos.x + rand() % 5, pos.y + rand() % 5};

    particle->velocity = velocity;
    sfCircleShape_setFillColor(particle->circle, sfYellow);
    sfCircleShape_setPosition(particle->circle, spawn_pos);
    sfCircleShape_setRadius(particle->circle, rand() % 3);
    sfClock_restart(particle->move_clock);
    particle->bounce_vel = -3.0;
}

void reset_particles(particle_t *particles)
{
    while (particles != NULL) {
        reset_particle(particles);
        particles = particles->next;
    }
}
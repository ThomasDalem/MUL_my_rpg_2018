/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_particles
*/

#include <stdlib.h>
#include <SFML/Graphics/CircleShape.h>
#include <stdio.h>
#include "structures.h"

static void init_particle(particle_t *particle, int x, int y)
{
    int direction = (rand() % 2 == 1) ? -1 : 1;
    sfVector2f velocity = {rand() % 4 * direction, (rand() % 4) * -1};
    sfVector2f spawn_pos = {x + rand() % 5, y + rand() % 5};

    particle->begin_pos = (sfVector2f){x, y};
    particle->velocity = velocity;
    particle->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(particle->circle, sfYellow);
    sfCircleShape_setPosition(particle->circle, spawn_pos);
    sfCircleShape_setRadius(particle->circle, rand() % 3);
    particle->move_clock = sfClock_create();
    particle->bounce_vel = -3.0;
}

static particle_t *create_particle(particle_t *next, int x, int y)
{
    particle_t *particle = malloc(sizeof(particle_t));

    if (particle == NULL)
        return (NULL);
    init_particle(particle, x, y);
    particle->next = next;
    return (particle);
}

particle_t *create_particles(int number, int x, int y)
{
    particle_t *particles = NULL;

    for (int i = 0; i < number; i ++) {
        particles = create_particle(particles, x, y);
        if (particles == NULL)
            return (NULL);
    }
    return (particles);
}

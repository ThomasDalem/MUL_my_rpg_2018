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

static void init_particle(particle_t *particle)
{
    int direction = 1;

    direction = (rand() % 2 == 1) ? -1 : 1;
    particle->color = sfRed;
    particle->circle = sfCircleShape_create();
    sfCircleShape_setFillColor(particle->circle, particle->color);
    particle->velocity = (sfVector2f){rand() % 5 * direction, (rand() % 4) * -1};
    sfCircleShape_setPosition(particle->circle, (sfVector2f){500, 400});
    sfCircleShape_setRadius(particle->circle, 5);
    particle->move_clock = sfClock_create();
    particle->bounce_vel = -5.0;
    particle->y_clock = sfClock_create();
}

static particle_t *create_particle(particle_t *next)
{
    particle_t *particle = malloc(sizeof(particle_t));

    if (particle == NULL)
        return (NULL);
    init_particle(particle);
    particle->next = next;
    return (particle);
}

particle_t *create_particles(int number)
{
    particle_t *particles = NULL;

    for (int i = 0; i < number; i++) {
        particles = create_particle(particles);
        if (particles == NULL)
            return (NULL);
    }
    return (particles);
}

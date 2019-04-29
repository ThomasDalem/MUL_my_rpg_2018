/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** move_particles
*/

#include <stdlib.h>
#include <SFML/Graphics/CircleShape.h>
#include <math.h>
#include "structures.h"

static void move_particle(particle_t *particles)
{
    sfTime time = sfClock_getElapsedTime(particles->y_clock);
    float elapsed_time = sfTime_asSeconds(time);
    sfVector2f pos = sfCircleShape_getPosition(particles->circle);

    particles->velocity.y += 0.1;
    particles->velocity.x /= 1.01;
    if (pos.y + particles->velocity.y > 800)
        particles->velocity.y = 800 - pos.y;
    if (abs(particles->velocity.x) < 0)
        particles->velocity.x = 0;
    if (pos.y >= 800) {
        sfCircleShape_move(particles->circle, (sfVector2f){0, pos.y - 800});
        particles->velocity.y = particles->bounce_vel;
        particles->bounce_vel *= 0.4;
    }
    sfCircleShape_move(particles->circle, particles->velocity);
}

void move_particles(particle_t *particles)
{
    sfTime time;
    float elapsed_time = 0.0f;

    while (particles != NULL) {
        time = sfClock_getElapsedTime(particles->move_clock);
        elapsed_time = sfTime_asSeconds(time);
        if (elapsed_time > 0.008f) {
            move_particle(particles);
            sfClock_restart(particles->move_clock);
        }
        particles = particles->next;
    }
}

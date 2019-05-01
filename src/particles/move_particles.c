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

static void change_y_pos(particle_t *particle, float beginning_y)
{
    sfVector2f pos = sfCircleShape_getPosition(particle->circle);
    sfVector2f new_pos;

    if (pos.y + particle->velocity.y > beginning_y + 200)
        particle->velocity.y = beginning_y + 200 - pos.y;
    if (pos.y >= beginning_y + 200) {
        new_pos = (sfVector2f){0, beginning_y + 200 - pos.y};
        sfCircleShape_move(particle->circle, new_pos);
        particle->velocity.y = particle->bounce_vel;
        particle->bounce_vel *= 0.4;
    }
}

static void move_particle(particle_t *particle)
{
    sfColor color = sfCircleShape_getFillColor(particle->circle);

    particle->velocity.y += 0.1;
    particle->velocity.x /= 1.01;
    color.a = (color.a == 0) ? 0 : color.a - 1;
    color.g = (color.g == 0) ? 140 : color.g - 1;
    sfCircleShape_setFillColor(particle->circle, color);
    if (abs(particle->velocity.x) < 0)
        particle->velocity.x = 0;
    change_y_pos(particle, particle->begin_pos.y);
    sfCircleShape_move(particle->circle, particle->velocity);
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

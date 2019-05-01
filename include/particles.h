/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particles
*/

#ifndef PARTICLES_H_
#define PARTICLES_H_

#include "structures.h"

particle_t *create_particles(int number, int x, int y);
void move_particles(particle_t *particles);
void free_particles(particle_t *particles);
void reset_particles(particle_t *particles);

#endif /* !PARTICLES_H_ */

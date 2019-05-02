##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

SRC =	src/collisions/check_collisions.c			\
		src/collisions/collision.c					\
		src/display/disp.c							\
		src/display/disp_invent.c 					\
		src/entities/anime_ennemie.c				\
		src/entities/discuss.c 						\
		src/free/close.c							\
		src/free/free.c                         	\
        src/free/music_free.c                   	\
        src/free/perso_free.c                   	\
		src/fight/diff.c 							\
		src/fight/disp_hud.c 						\
		src/fight/alive.c 							\
		src/fight/attack.c 							\
		src/fight/check_fight.c 					\
		src/fight/defense.c 						\
		src/fight/ennemi_action.c 					\
		src/fight/ennemi_ai.c 						\
		src/fight/fight_event.c 					\
		src/fight/fight_move.c 						\
		src/fight/jump.c 							\
		src/fight/orient.c 							\
		src/fight/repulse.c 						\
		src/initialisation/init.c					\
		src/initialisation/init_equipement.c 		\
		src/initialisation/init_ennemie.c			\
		src/initialisation/init_fight_perso.c 		\
		src/initialisation/init_inventory.c			\
		src/initialisation/init_menu.c				\
		src/initialisation/init_pause.c				\
		src/initialisation/init_phrase.c 			\
		src/initialisation/init_pnj.c 				\
		src/initialisation/init_sound.c				\
		src/initialisation/init_use_throw_button.c 	\
		src/initialisation/set_stats_equipement.c	\
		src/inputs/event.c							\
		src/inputs/mouse.c							\
		src/inputs/select.c							\
		src/inventory/inventory_gestion.c			\
		src/inventory/inventory_use_throw.c			\
		src/loose/loose.c 							\
		src/loose/loose_button.c 					\
		src/main.c									\
		src/maps/create_graph.c						\
		src/maps/get_top_left_map.c					\
		src/maps/change_map.c						\
		src/maps/get_objects.c						\
		src/maps/remove_endline.c					\
		src/maps/get_object_stats.c					\
		src/maps/add_particles.c					\
		src/maps/free_graph.c						\
		src/menus/button.c 							\
		src/menus/menu.c							\
		src/moves/move.c							\
		src/moves/move_ennemie.c					\
		src/moves/move_player.c						\
		src/menus/pause.c							\
		src/particles/create_particles.c			\
		src/particles/move_particles.c				\
		src/particles/free_particles.c				\
		src/particles/reset_particles.c				\
		src/system/game.c							\
		src/system/reboot.c 						\
        src/system/sound.c                          \
		src/tools/create_sprite.c 					\
		src/tools/set_str.c							\
		src/tools/tools.c							\

OBJ =	$(SRC:.c=.o)

OBJC =	$(SRCC:.c=.o)

NAME =	my_rpg

INC = -I./include

LIB = -L./lib/my -lmy

LE = -lcsfml-graphics -lcsfml-audio -lcsfml-system

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CRITERION = unit_tests

CC = gcc -g3

CPPFLAGS = -I./include

ARGUMENTS =

all:	$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib/my
			$(CC) -o $(NAME) $(OBJ) $(INC) $(LIB) $(LE) $(WALL)

exe:		$(NAME)
			clear
			./$(NAME)

valgrind:	$(OBJ)
			make -C ./lib/my
			gcc -o $(NAME) $(OBJ) $(LIB) $(LE)
			rm -f $(OBJ)
			valgrind ./$(NAME) $(ARGUMENTS)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../libmy.a
		rm -f lib/libmy.a

re: fclean all

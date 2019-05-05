##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## RPG
##

SRC =	src/collisions/check_collisions.c			\
		src/collisions/check_enemy_collisions.c		\
		src/collisions/collision.c					\
		src/display/disp.c							\
		src/display/disp_invent.c					\
		src/entities/anime_ennemie.c				\
		src/entities/discuss.c						\
		src/equipements/add_equipement.c			\
		src/equipements/sell.c						\
		src/fight/alive.c							\
		src/fight/after_fight.c 					\
		src/fight/attack.c							\
		src/fight/check_fight.c						\
		src/fight/defense.c							\
		src/fight/diff.c							\
		src/fight/disp_hud.c						\
		src/fight/ennemi_action.c					\
		src/fight/ennemi_ai.c						\
		src/fight/fight_event.c						\
		src/fight/fight_move.c						\
		src/fight/fight_norm.c 						\
		src/fight/jump.c							\
		src/fight/orient.c							\
		src/fight/repulse.c							\
		src/fight/free_obj.c						\
		src/fight/potion_effect.c 					\
		src/fight/remove_enemy.c					\
		src/free/close.c							\
		src/free/free.c								\
		src/free/music_free.c						\
		src/free/perso_free.c						\
		src/initialisation/create_string_equip.c 	\
		src/initialisation/init.c					\
		src/initialisation/init_ennemie.c			\
		src/initialisation/init_equipement.c		\
		src/initialisation/init_fight_perso.c		\
		src/initialisation/init_inventory.c			\
		src/initialisation/init_menu.c				\
		src/initialisation/init_pause.c				\
		src/initialisation/init_phrase.c			\
		src/initialisation/init_pnj.c				\
		src/initialisation/init_potion.c 			\
		src/initialisation/init_sell.c				\
		src/initialisation/init_sell_equipement.c	\
		src/initialisation/init_sound.c				\
		src/initialisation/init_use_throw_button.c	\
		src/initialisation/set_stats_equipement.c	\
		src/inputs/event.c							\
		src/inputs/mouse.c							\
		src/inventory/inventory_gestion.c			\
		src/inventory/inventory_use_throw.c			\
		src/inventory/set_potion_str.c 				\
		src/inventory/switch_equipement.c 			\
		src/loose/loose.c 							\
		src/loose/loose_button.c					\
		src/main.c									\
		src/maps/add_particles.c					\
		src/maps/change_map.c						\
		src/maps/create_graph.c						\
		src/maps/get_top_left_map.c					\
		src/maps/get_objects.c						\
		src/maps/remove_endline.c					\
		src/maps/get_object_stats.c					\
		src/maps/free_graph.c						\
		src/maps/add_enemy.c						\
		src/maps/add_seller.c						\
		src/menus/button.c							\
		src/menus/menu.c							\
		src/menus/pause.c							\
		src/moves/move.c							\
		src/moves/move_ennemie.c					\
		src/moves/move_player.c						\
		src/moves/change_animation.c				\
		src/moves/get_distance.c					\
		src/moves/enemy_movement.c					\
		src/moves/norm_move.c 						\
		src/particles/create_particles.c			\
		src/particles/move_particles.c				\
		src/particles/free_particles.c				\
		src/particles/reset_particles.c				\
		src/quests/create_quest.c					\
		src/quests/display_quest.c					\
		src/quests/set_quest_attributes.c			\
		src/quests/set_quest_rewards.c				\
		src/quests/quest_end.c						\
		src/system/game.c							\
		src/system/reboot.c							\
		src/system/sound.c							\
		src/system/intro.c							\
		src/system/end.c							\
		src/tools/create_sprite.c					\
		src/tools/set_str.c							\
		src/tools/tools.c							\
		src/option/option.c							\
		src/option/init_option.c

OBJ =	$(SRC:.c=.o)

NAME =	my_rpg

INC = -I./include

LIB = -L./lib/my -lmy

LE = -lcsfml-graphics -lcsfml-audio -lcsfml-system

CRIT = --coverage -lcriterion

WALL = -Wall -Wextra -Werror

CC = gcc -g3

CPPFLAGS = -I./include

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
			valgrind ./$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../libmy.a
		rm -f lib/libmy.a

re: fclean all

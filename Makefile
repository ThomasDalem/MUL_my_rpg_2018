##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

SRC =	src/anime_ennemie.c							\
		src/close.c									\
		src/discuss.c 								\
		src/disp.c									\
		src/collisions/check_collisions.c			\
		src/collisions/collision.c					\
		src/event.c									\
		src/free/free.c                         	\
        src/free/music_free.c                   	\
        src/free/perso_free.c                   	\
		src/game.c									\
		src/initialisation/init.c					\
		src/initialisation/init_equipement.c 		\
		src/initialisation/init_ennemie.c			\
		src/initialisation/init_inventory.c			\
		src/initialisation/init_menu.c				\
		src/initialisation/init_pause.c				\
		src/initialisation/init_phrase.c 			\
		src/initialisation/init_pnj.c 				\
		src/initialisation/init_sound.c				\
		src/initialisation/set_stats_equipement.c	\
		src/inventory_gestion.c						\
		src/main.c									\
		src/menu.c									\
		src/mouse.c									\
		src/moves/move.c							\
		src/moves/move_ennemie.c					\
		src/moves/move_player.c						\
		src/pause.c									\
		src/select.c								\
		src/set_str.c								\
		src/tools.c									\

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

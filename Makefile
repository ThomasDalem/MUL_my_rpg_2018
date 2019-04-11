##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

SRC =	src/anime_ennemie.c 	\
		src/close.c				\
		src/disp.c 				\
		src/event.c				\
		src/init.c				\
		src/init_ennemie.c 		\
		src/init_inventory.c	\
		src/inventory_gestion.c	\
		src/init_menu.c			\
		src/init_pause.c		\
		src/game.c				\
		src/main.c				\
		src/menu.c				\
		src/mouse.c				\
		src/move_ennemie.c 		\
		src/move.c				\
		src/pause.c				\
		src/select.c 			\
		src/set_str.c			\
		src/tools.c				\

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
			make -C ./lib
			gcc -o $(NAME) $(OBJ) $(LIB) $(LE) $(VALGRIND)
			rm -f $(OBJ)
			valgrind ./$(NAME) $(ARGUMENTS)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		rm -f ../libmy.a
		rm -f lib/libmy.a

re: fclean all

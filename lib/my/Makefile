##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Le Makefile de la lib
##

SRC =	my_putint_in_str.c	\
		int_to_char.c 		\
		my_putstr.c			\
		my_revstr.c			\
		my_strcpy.c 		\
		my_str.c			\
		my_strlen.c 		\
		my_strcat.c 		\
		my_strmcat.c		\
		my_getnbr.c			\
		my_strcmp.c			\
		reallocation.c 		\
		my_str_to_word_array.c 	\

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

NAME2 = my.h

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			rm -f $(OBJ)

clean: 
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)

re: fclean all

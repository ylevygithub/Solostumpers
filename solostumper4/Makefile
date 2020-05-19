##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

SRC		=		main.c \
				checkvowels.c

OBJ		=		$(SRC:.c=.o)

NAME	=		geekNameFormatter

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -g $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

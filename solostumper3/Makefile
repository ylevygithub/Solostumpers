##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

SRC		=		main.c

OBJ		=		$(SRC:.c=.o)

NAME	=		fizzbuzz

all:	$(NAME)

$(NAME):		$(OBJ)
	gcc -g $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

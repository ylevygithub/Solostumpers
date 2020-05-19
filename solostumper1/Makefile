##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make library
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	head

all:	$(OBJ)
	@gcc -o $(NAME) $(SRC) -g
	@echo "-COMPILATION DONE-"

clean:
	@rm -f $(OBJ)
	@echo "-CLEANED-"

fclean:	clean
	@rm -f $(NAME)
	@echo "-FCLEANED-"

re:	fclean all

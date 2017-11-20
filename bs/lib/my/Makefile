##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile lib
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -pedantic -I ../../include/

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re : fclean all

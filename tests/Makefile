##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -pedantic -I ../include/

LIB	=	-L ../lib/my/ -lmy

CRIT	=	-lcriterion

SRC	=	test_exemple.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tests

all: $(NAME)

$(NAME): 	$(OBJ)
	make -C ../lib/my/
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LIB) $(CRIT)
	rm -f $(OBJ)
	make clean -C ../lib/my/

clean:
	rm -f $(OBJ)
	make clean -C ../lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ../lib/my/

re: fclean all

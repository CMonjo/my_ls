##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -pedantic -I include/

LIB	=	-L lib/my -lmy
LIB	+=	-L lib/printf -lprintf

SRC	=	sources.c

OBJ	=	$(SRC:.c=.o)

NAME	=	nom_de_l_executable

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my/
	make -C ./lib/printf/
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)
	rm -f $(OBJ)
	make clean -C ./lib/my/
	make clean -C ./lib/printf/

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my/
	make clean -C ./lib/printf/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/
	make fclean -C ./lib/printf/

re: fclean all

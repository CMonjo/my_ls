##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -W -Werror -I include/

LIB	=	-L lib/my -lmy
LIB	+=	-L lib/printf -lprintf

SRC	=	my_ls.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

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

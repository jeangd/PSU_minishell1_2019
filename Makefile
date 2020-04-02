##
## EPITECH PROJECT, 2019
## CPool_Day12_2019
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -g

all:	$(NAME)

lib_com:
	cd ./lib/my && $(MAKE)

$(NAME):	$(OBJ) lib_com
	$(CC) $(OBJ) -o $(NAME) -L ./lib/my -I./include/ -lmy $(CFLAGS)

clean:
	cd ./lib/my && $(MAKE)
	rm -f $(OBJ)

fclean:	clean
	(cd ./lib/my; make fclean)
	rm -f $(NAME)

re:	fclean all

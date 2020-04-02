##
## EPITECH PROJECT, 2019
## CPool_Day10_2019
## File description:
## Makefile
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

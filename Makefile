##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC		=	src/check.c \
			src/engine.c \
			src/main.c \
			src/math.c \
			src/output.c

CFLAGS	=	-std=gnu11 -Wall -Wextra -I include

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-o

LIB		=	-g -lm

NAME	=	202unsold

all:	$(NAME)

$(NAME):$(OBJ)
	gcc $(OBJ) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	=	epiclang

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -Werror -g3

SRC	=	shell.c \
		my_printf.c \
		read.c \
		execute.c \
		parsing.c \
		main.c \
		exec.c \
		bases_functions.c \
		setenv.c \
		cd.c

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) -g3

clean:
	rm -f *~
	rm -f *#
fclean:
	rm -f $(NAME)
	rm -f *~
	rm -f *#

re:	fclean all

.PHONY:	all clean fclean re

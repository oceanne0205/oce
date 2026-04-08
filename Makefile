##
61;7600;1c## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile
##

CC	=	epiclang

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -Werror -g3

SRC	=	main.c \
		kebab_formatter.c \

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

tests_run:
	@echo "No tests yet"

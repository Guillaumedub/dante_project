##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	../src/maze_gen_fct.c			\
		../src/maze_gen_fct2.c			\
		../src/maze_fct.c				\
		../src/liste_chainee_fct.c		\
		../src/liste_chainee_fct2.c		\
		../src/malloc_2d_array.c		\
		../src/my_len_of_array.c		\
		../src/free_array.c				\
		generator.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch *.tmp

NAME	=	generator

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

unit_tests: fclean libmy.a
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out

clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all

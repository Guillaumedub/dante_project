##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	../src/maze_fct.c				\
		../src/maze_solve_fct.c			\
		../src/maze_solve_fct2.c		\
		../src/liste_chainee_fct.c		\
		../src/liste_chainee_fct2.c		\
		../src/free_array.c				\
		../src/malloc_2d_array.c		\
		../src/my_len_of_array.c		\
		solver.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch *.tmp

NAME	=	solver

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

unit_tests:
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

##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ./include

all:
	cd ./solver && $(MAKE)
	cd ./generator && $(MAKE)

unit_tests: fclean libmy.a
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out

clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	make fclean -C ./solver
	make fclean -C ./generator

re: fclean all

.PHONY = clean fclean re all

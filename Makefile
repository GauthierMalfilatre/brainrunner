##
## EPITECH PROJECT, 2024
## DAMIEN
## File description:
## Makefile
##

SRC =	main.c

OBJ = $(SRC:.c=.o)

NAME = brainrunner

CFLAGS = -Wall

all: $(NAME)

$(NAME): $(OBj)
	rm -f include/my.h
	rm -f include/my_printf.h
	make -C lib/my
	gcc -o $(NAME) $(SRC) -Llib/ -Iinclude/ -lmy

run: re
	./$(NAME) test.bf
	gcc temp.c
	rm temp.c
	./a.out

debug:	all
	valgrind ./$(NAME)

clean:
	find . -name "*~" -delete -o -name "#*#" -delete -o -name "*.out" -delete
	find . -name "*.o" -delete -o -name "unit_tests"  -delete
	find . -name "*.a" -delete -o -name "*.log" -o -name "'#*#'" -delete
	find . -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean:
	rm -f $(NAME)
	make clean

code: fclean
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log

test: re
	gcc -w -o unit_test tests/*.c --coverage -lcriterion -L. -lmy
	./unit_test
	make fclean > /dev/null
	rm unit_test > /dev/null

push:
	make fclean
	git add .
	@echo "What did you change ?" ; read COMMIT ; git commit -m "$$COMMIT"
	git push -u origin main

re: fclean all

kronk:
	echo "Oh ouais."

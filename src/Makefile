CC = gcc
FLAGS = -g
# FLAGS = -Wall -Werror -Wextra -std=c11
DIRS = s21_decimal

s21_decimal : clean s21_decimal.h s21_decimal.c
	$(CC) $(FLAGS) s21_decimal.h s21_decimal.c -o s21_decimal
	./s21_decimal

clean : 
	rm -rf $(DIRS)
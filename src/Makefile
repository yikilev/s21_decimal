CFLAGS = -Wall -Wextra -Werror -std=c11 --coverage
SRC_DIRS = arithmetic binary helpers other
SRCS = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS = $(SRCS:.c=.o)
TEST_OBJS = tests/test.o

all: s21_decimal.a

# Цель для сборки библиотеки
s21_decimal.a: $(OBJS)
	ar rcs $@ $^

# Правила для объектных файлов
%.o: %.c
	gcc $(CFLAGS) -I . -c $< -o $@

test.a: $(TEST_OBJS)
	ar rcs $@ $^

covered: $(OBJS)
	ar rcs s21_decimal.a $(OBJS)

test: covered test.a
	gcc $(CFLAGS) -o test tests/test.o s21_decimal.a test.a -lcheck -lpthread -pthread -lm -lsubunit -lgcov
	./test

leaks: test
	valgrind --leak-check=yes  ./test

clean:
	rm -rf *.o *.a *.gcno *.gcda ./tests/*.o ./tests/*.gcno ./arithmetic/*.o ./binary/*.o ./helpers/*.o ./other/*.o *.info *.html gcov_report test

gcov_report: test
	lcov -t "s21_decimal" -o s21_decimal.info -c -d .
	genhtml -o gcov_report s21_decimal.info

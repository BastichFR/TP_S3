all: test.o is_partition.o
	gcc   test.o is_partition.o   -o test

test.o : test.c
	gcc -Wall -Wextra   -c -o test.o test.c

is_partition.o : is_partition.c
	gcc -Wall -Wextra   -c -o is_partition.o is_partition.c

clean:
	rm -f test.o is_partition.o
	rm -f test

run:
	time valgrind --leak-check=full ./test

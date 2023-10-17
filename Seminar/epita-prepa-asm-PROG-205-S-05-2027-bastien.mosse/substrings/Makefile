all :
	gcc -Wall -Wextra -o main *.c

clean : 
	rm main

run :
	time valgrind --leak-check=full ./main

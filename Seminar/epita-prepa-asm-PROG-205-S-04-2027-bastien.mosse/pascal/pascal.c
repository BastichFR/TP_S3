#include <stdio.h>
#include "pascal.h"

// Prints Pascal's Triangle.
// tr: triangle to print
// len: length of the triangle.
void print_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
	for(size_t x = 0; x < len; x++){
		for(size_t y = 0; y < x+1; y++){
			printf("%5u ", tr[x][y]);
		}
		printf("\n");
	}
}

// Generates Pascal's Triangle.
// tr: triangle to generate.
// len: length of the triangle.
void pascal_triangle(unsigned int tr[][MAX_LEN], size_t len)
{
	for(size_t x = 0; x  < len; x++){
		for(size_t y = 0; y < x+1; y++){
			if(y == 0 || x == y){
				tr[x][y] = 1;
			} else {
				tr[x][y] = tr[x-1][y-1] + tr[x-1][y];
			}
		}
	}
}

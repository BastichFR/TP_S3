#include <stdio.h>

void print_matrix(char s[], double m[], size_t rows, size_t cols)
{
	printf("%s = \n", s);
	for(size_t x = 0; x < rows; x++){
		for(size_t y = 0; y < cols; y++){
			printf("%4g", m[x * cols +  y]);
		}
		printf("\n");
	}
}

void transpose(double m[], size_t rows, size_t cols, double r[])
{
	for(size_t x = 0; x < rows; x++){
                for(size_t y = 0; y < cols; y++){
			r[x + rows * y] = m[x * cols +  y];
                }
        }
}

void add(double m1[], double m2[], size_t rows, size_t cols, double r[])
{
	for(size_t x = 0; x < rows; x++){
		for(size_t y = 0; y < cols; y++){
			r[x * cols + y] = m1[x * cols + y] + m2[x * cols + y];
		}
	}
}

void mul(double m1[], double m2[], size_t r1, size_t c1, size_t c2, double r[])
{
	for(size_t i = 0; i < r1; i++){
		for(size_t j = 0; j < c2; j++){
			for(size_t k = 0; k < c1; k++){
				r[i * r1 + j] += m1[i * c1 + k] * m2[k * c2 + j];
			}
		}
	}
}

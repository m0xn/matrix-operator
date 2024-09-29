#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "../lib/matrix.h"

#define MAX_CHAR_COUNT 180
#define MAX_ARRAY_SIZE 25 // Support for 5x5 matrix for now 

int main()
{
	Matrix m, n, j;

	fill_matrix(&m, 3, 2, 10, INCREMENT, 2);
	fill_matrix(&n, 2, 3, 10, DECREMENT, 2);

	printf("M = \n");
	print_matrix(m);
	printf("\n");

	printf("N = \n");
	print_matrix(n);
	printf("\n");

	printf("N * M = \n");
	j = mult_matrices(n, m);
	print_matrix(j);
	printf("\n");
	return 0;
}

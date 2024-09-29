#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	Matrix m, n, j;
	int rows, cols;

	printf("Introduce el número de filas: ");
	scanf("%d", &rows);
	printf("Introduce el número de columnas: ");
	scanf("%d", &cols);

	fill_matrix(&m, rows, cols, 1, INCREMENT, 1);
	fill_matrix(&n, rows, cols, rows*cols, DECREMENT, 1);
	fill_matrix(&j, rows, cols, 1, CONSTANT, 1);

	printf("\n M (INC 1->%d) = \n", rows*cols);
	print_matrix(m);

	printf("\n N (DEC %d->1) = \n", rows*cols);
	print_matrix(n);

	printf("\n J (CONST 1) = \n");
	print_matrix(j);
	return 0;
}

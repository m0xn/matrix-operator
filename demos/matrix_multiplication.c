#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main() {
	Matrix m, n;
	int rows, cols;

	printf("Introduce el número de filas: ");
	scanf("%d", &rows);
	printf("Introduce el número de columnas: ");
	scanf("%d", &cols);

	fill_matrix(&m, rows, cols, 1, INCREMENT, rows);
	fill_matrix(&n, cols, rows, rows*cols, DECREMENT, cols);

	printf("\nM = \n");
	print_matrix(m);

	printf("\nN = \n");
	print_matrix(n);

	printf("\nM * N = \n");
	print_matrix(mult_matrices(m, n));

	printf("\nN * M = \n");
	print_matrix(mult_matrices(n, m));
}

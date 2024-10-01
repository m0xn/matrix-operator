#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main() {
	Matrix m, n;
	int rows, cols, scalar;

	printf("Introduce el número de filas: ");
	scanf("%d", &rows);
	printf("Introduce el número de columnas: ");
	scanf("%d", &cols);
	printf("Introduce la cte para multiplicar: ");
	scanf("%d", &scalar);

	fill_matrix(&m, rows, cols, 1, INCREMENT, rows);
	n = scalar_mult(m, scalar);
	printf("\nM = \n");
	print_matrix(m);

	switch (scalar) {
		case 0:
			printf("\n0 (Matriz nula) = \n");
			break;
		case -1:
			printf("\n-M = \n");
			break;
		default:
			printf("\n%dM = \n", scalar);
			break;

	}

	print_matrix(n);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	Matrix m, n;
	int rows, cols;

	printf("Introduce el número de filas de las matrices: ");
	scanf("%d", &rows);
	printf("Introduce el número de columnas de las matrices: ");
	scanf("%d", &cols);

	fill_matrix(&m, rows, cols, 1, INCREMENT, cols);
	fill_matrix(&n, rows, cols, rows*cols, DECREMENT, rows);
	
	printf("\nM = \n");
	print_matrix(m);

	printf("\nN = \n");
	print_matrix(n);

	printf("\nM + N = \n");
	print_matrix(add_matrices(m, n, false));

	printf("\nM - N = \n");
	print_matrix(add_matrices(m, n, true));
}

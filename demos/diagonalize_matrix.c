#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	Matrix m;
	int order;

	printf("Introduce el orden de la matriz: ");
	scanf("%d", &order);

	fill_matrix(&m, order, order, 1, INCREMENT, 1);

	diagonalize_matrix(&m);

	printf("\nM (diagonalized) = \n");
	print_matrix(m);
	return 0;
}

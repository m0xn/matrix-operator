#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	Matrix i, m;
	int order;

	printf("Introduce el orden de la matrices: ");
	scanf("%d", &order);

	identity_matrix(&i, order);
	fill_matrix(&m, order, order, 1, INCREMENT, 1);

	printf("\nI_%d = \n", order);
	print_matrix(i);
	printf("La matriz I_%d es: %s\n", order, symmetric_matrix(i) ? "Simétrica" : "No simétrica");

	printf("\nM = \n");
	print_matrix(m);
	printf("La matriz M es: %s\n", symmetric_matrix(m) ? "Simétrica" : "No simétrica");
	return 0;
}

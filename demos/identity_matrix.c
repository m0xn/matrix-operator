#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	int order;
	Matrix i;
	printf("Introduce el orden de la matriz identidad: ");
	scanf("%d", &order);

	identity_matrix(&i, order);

	printf("\nI_%d = \n", order);
	print_matrix(i);
	printf("\n");
	return 0;
}

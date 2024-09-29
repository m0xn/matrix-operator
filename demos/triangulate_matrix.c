#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

int main()
{
	Matrix m, m_low, m_up;
	int order;

	printf("Introduce el orden de la matriz: ");
	scanf("%d", &order);

	fill_matrix(&m, order, order, 1, INCREMENT, 1);

	copy_matrix(&m_low, m);
	copy_matrix(&m_up, m);

	triangulate_matrix(&m_low, LOWER);
	triangulate_matrix(&m_up, UPPER);

	printf("\nM (Superior) = \n");
	print_matrix(m_up);

	printf("\nM (Inferior) = \n");
	print_matrix(m_low);
	return 0;
}

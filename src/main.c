#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h"

#define MAX_CHAR_COUNT 180
#define MAX_ARRAY_SIZE 25 // Support for 5x5 matrix for now 

void rm_whitespace(char *src)
{
	char *tmp = (char*)malloc(strlen(src) + 1);
	char *rdr = src, *out = tmp;
	while (*rdr != '\0') {
		if (*rdr == ' ')
			while(*(++rdr) == ' ');
		*(out++) = *(rdr++);
	}
	strcpy(src, tmp);
	free(tmp);
}

void parse_matrix(int *elements, int *rows, int *cols, char *raw_input, const char* delimiter) {
	char *row = strtok(raw_input, delimiter);
	char *endptr;
	int i = 0;
	while (row) {
		(*rows)++;
		while (*row != '\0') {
			elements[i++] = strtol(row, &endptr, 10);
			row += *endptr == ',' || *endptr == '\n' ? endptr - row + 1 : endptr - row; 
		}
		row = strtok(NULL, delimiter);
	}
	*cols = i / *rows;
}

int main()
{
	char *input = (char*)malloc(MAX_CHAR_COUNT);
	int *elements = (int*)malloc(sizeof(int)*MAX_ARRAY_SIZE);
	size_t max_input_size = MAX_CHAR_COUNT;
	int rows = 0, cols = 0;

	printf("Introduce your matrix (elements are separated by ',' and rows by ';'):\n");
	getline(&input, &max_input_size, stdin);
	rm_whitespace(input);
	parse_matrix(elements, &rows, &cols, input, ";");

	Matrix m;
	init_matrix(&m, rows, cols, elements);
	/*print_matrix(m);*/

	/*Matrix i;*/
	/*int order;*/
	/*printf("Introduce the order of the identity matrix: ");*/
	/*scanf("%d", &order);*/
	/*identity_matrix(&i, order);*/
	triangulate_matrix(&m, UPPER);
	print_matrix(m);
	/*bool output = symmetric_matrix(m);*/
	/*printf("The matrix is: %s\n", output ? "Symmetric" : "Non-symmetric");*/
	return 0;
}

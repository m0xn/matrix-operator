#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "../lib/matrix.h" 

#define MAX_CHAR_COUNT 100
#define MAX_ELEMENT_COUNT 100

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

void parse_matrix(int *elements, int *rows, int *cols, char *raw_input, const char* delimiter)
{
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
	// User input retreival and parsing 
	size_t max_char_count = MAX_CHAR_COUNT;
	char *raw_input = (char*)malloc(max_char_count);

	printf("Escribe tu matriz (usa ',' para separar elementos y ';' para separar columnas):\n");
	getline(&raw_input, &max_char_count, stdin);
	rm_whitespace(raw_input);

	int *elements = (int*)malloc(sizeof(int)*MAX_ELEMENT_COUNT);
	const char *delimiter = ";";
	int rows, cols;
	parse_matrix(elements, &rows, &cols, raw_input, delimiter);

	// Matrix initialization and printing
	Matrix m;
	init_matrix(&m, rows, cols, elements);

	printf("\nM =\n");
	print_matrix(m);
	printf("\n");
	return 0;
}

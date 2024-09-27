#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

#define MAX_CHAR_COUNT 100

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
	while (row) {
		*rows++;
		while (*row == '\0') {
			strtol(row, &endptr, 10);
			row += endptr - row;
		}
	}
}

int main()
{
	/*size_t max_char_count = 180;*/
	/*char *input = (char*)malloc(max_char_count);*/
	/*printf("Introduce your matrix: ");*/
	/*getline(&input, &max_char_count, stdin);*/
	/*rm_whitespace(input);*/
	/*printf("The resulting input is: %s\n", input);*/
	/**/
	/*Matrix m;*/
	/*size_t max_char_count = MAX_CHAR_COUNT; */
	/*char *matA = (char*)malloc(max_char_count);*/
	/*const char *row_delim = ";";*/
	/*printf("Introduce your matrix: ");*/
	/*getline(&matA, &max_char_count, stdin);*/
	/**/
	/*// COMPLEX INPUT PARSER */
	/*// Text preprocessor*/
	/*int *elements = (int*)malloc(sizeof(int)*10);*/
	/*int j = 0, k = 0;*/
	/**/
	/*// Parser*/
	/*char *row = strtok(p_matA, row_delim);*/
	/*int initial_length = strlen(row), current_length = strlen(row);*/
	/*while (row) {*/
	/*	if (initial_length != current_length) {*/
	/*		fprintf(stderr, "[ERROR]: Inconsistent row elements\n");*/
	/*		exit(1);*/
	/*	}*/
	/**/
	/*	j++;*/
	/*	char *endptr;*/
	/*	while (*row != '\0') {*/
	/*		if (*row == ',')*/
	/*			row++;*/
	/*		elements[k++] = strtol(row, &endptr, 10);*/
	/*		row += endptr - row;*/
	/*	}*/
	/*	row = strtok(NULL, row_delim);*/
	/*	current_length = row ? strlen(row) : 0;*/
	/*}*/
	/**/
	/*printf("The numbers read from the input are:\n");*/
	/*for (int i = 0; i < k; ++i)*/
	/*	printf("%d\n", elements[i]);*/
	/**/
	/*int rows = j, cols = k/j;*/
	/*printf("The dimension of the parsed matrix is: %dx%d\n", j, k/j);*/
	/**/
	/*init_matrix(&m, rows, cols, elements);*/
	/*print_matrix(&m);*/
	/**/
	/*free(p_matA);*/
	return 0;
}

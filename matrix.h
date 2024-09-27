#pragma once

typedef struct {
	int rows, cols;
	int **elements;
} Matrix;

void init_matrix(Matrix *m_ref, int rows, int cols, int *elements)
{
	m_ref->rows = rows;
	m_ref->cols = cols;
	m_ref->elements = (int**)calloc(rows, sizeof(int*));
	
	for (int i = 0; i < rows; ++i) {
		int *row = (int*)calloc(cols, sizeof(int));
		for (int j = 0; j < cols; ++j)
			row[j] = elements[j+cols*i];
		m_ref->elements[i] = row;
	}
}

void print_matrix(Matrix *m_ref)
{
	for (int i = 0; i < m_ref->rows; ++i) {
		for (int j = 0; j < m_ref->cols; ++j) {
			printf(j == m_ref->cols - 1 ? "%d\n" : "%d, ", m_ref->elements[i][j]);
		}
	}
}

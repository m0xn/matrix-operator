#pragma once

typedef struct {
	int rows, cols;
	int **elements;
} Matrix;

typedef enum {
	UPPER,
	LOWER
} Triangulation; 

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

void print_matrix(Matrix m_ref)
{
	for (int i = 0; i < m_ref.rows; ++i) {
		for (int j = 0; j < m_ref.cols; ++j) {
			printf(j == m_ref.cols - 1 ? "%d\n" : "%d, ", m_ref.elements[i][j]);
		}
	}
}

bool square_matrix(Matrix m_ref) { return m_ref.cols == m_ref.rows; }

void identity_matrix(Matrix *m_ref, int order)
{
	int *elements = (int*)malloc(sizeof(int)*order*order);

	for (int i = 0; i < order*order; ++i)
		elements[i] = i % (order+1) == 0;

	init_matrix(m_ref, order, order, elements);
}

void triangulate_matrix(Matrix *m_ref, Triangulation tr)
{
	if (!square_matrix(*m_ref)) {
		fprintf(stderr, "[ERROR]: Matrix must be square (%d != %d)", m_ref->rows, m_ref->cols);
		return;
	}
	
	if (tr == LOWER) {
		for (int i = 1; i < m_ref->rows; ++i) {
			for (int j = 0; j < i; ++j) {
				m_ref->elements[i][j] = 0;
			}
		}
	} else {
		for (int i = m_ref->rows-1; i >= 0; --i) {
			for (int j = m_ref->cols; j > i; --j) {
				m_ref->elements[i][j] = 0;
			}
		}
	}
}

bool symmetric_matrix(Matrix m_ref)
{
	if (!square_matrix(m_ref)) {
		fprintf(stderr, "[ERROR]: Matrix must be square (%d != %d)", m_ref.rows, m_ref.cols);
		return false;
	}

	bool output;
	for (int i = 0; i < m_ref.rows - 1; ++i) {
		int j = i + 1;
		output = m_ref.elements[i][j] == m_ref.elements[j][i];
	}

	return output;
}


#pragma once

typedef struct {
	int rows, cols;
	int **elements;
} Matrix;

typedef enum {
	UPPER,
	LOWER
} Triangulation; 

typedef enum {
	CONSTANT = 0,
	INCREMENT = 1,
	DECREMENT = -1
} FillMode;

int max_element(Matrix m_ref)
{
	int max = m_ref.elements[0][0];

	for (int i = 0; i < m_ref.rows; ++i)
		for (int j = 0; j < m_ref.cols; ++j)
			max = m_ref.elements[i][j] > max 
				? m_ref.elements[i][j]
				: max;

	return max;
}

int min_element(Matrix m_ref)
{
	int min = m_ref.elements[0][0];

	for (int i = 0; i < m_ref.rows; ++i)
		for (int j = 0; j < m_ref.cols; ++j)
			min = m_ref.elements[i][j] < min 
				? m_ref.elements[i][j]
				: min;

	return min;
}

bool eq_dim_matrices(Matrix m, Matrix n) { return m.rows == n.rows && m.cols == n.cols; }

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

void fill_matrix(Matrix *m_ref, int rows, int cols, int num, FillMode fm, int step)
{
	int *elements = (int*)malloc(sizeof(int)*rows*cols);

	for (int i = 0; i < rows*cols; ++i)
		elements[i] = num + fm*i*step;

	init_matrix(m_ref, rows, cols, elements);
}

void print_matrix(Matrix m_ref)
{
	int max = max_element(m_ref);
	int min = min_element(m_ref);
	int digits = min < 0 
		? (int)trunc(log10(max)) + 2 // Account for negative sign paddinfor negative sign paddingg
		: (int)trunc(log10(max)) + 1;

	char *format = (char*)malloc(digits+5);
	sprintf(format, "%%%dd, ", digits);
	
	for (int i = 0; i < m_ref.rows; ++i) {
		for (int j = 0; j < m_ref.cols; ++j) {
			printf(format, m_ref.elements[i][j]);
			if (j == m_ref.cols - 1)
				printf("\n");
		}
	}
}

void copy_matrix(Matrix *dst, Matrix src)
{
	fill_matrix(dst, src.rows, src.cols, 0, CONSTANT, 0);

	for (int i = 0; i < src.rows; ++i)
		for (int j = 0; j < src.cols; ++j)
			dst->elements[i][j] = src.elements[i][j];
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
		for (int i = m_ref->rows-2; i >= 0; --i) {
			for (int j = m_ref->cols-1; j > i; --j) {
				m_ref->elements[i][j] = 0;
			}
		}
	}
}

void diagonalize_matrix(Matrix *m_ref)
{
	if (!square_matrix(*m_ref)) {
		fprintf(stderr, "[ERROR]: Matrix must be square (%d != %d)", m_ref->rows, m_ref->cols);
		return;
	}

	for (int i = 1; i < m_ref->rows; ++i)
		for (int j = 0; j < i; ++j)
			m_ref->elements[i][j] = m_ref->elements[j][i] = 0;
}

bool symmetric_matrix(Matrix m_ref)
{
	if (!square_matrix(m_ref)) {
		fprintf(stderr, "[ERROR]: Matrix must be square (%d != %d)", m_ref.rows, m_ref.cols);
		return false;
	}

	bool output;
	for (int i = 1; i < m_ref.rows; ++i)
		for (int j = 0; j < i; ++j)
			output = m_ref.elements[i][j] == m_ref.elements[j][i];

	return output;
}

Matrix add_matrices(Matrix m, Matrix n, bool substract) {
	Matrix result;
	fill_matrix(&result, m.rows, m.cols, 0, CONSTANT, 0);

	if (!eq_dim_matrices(m, n)) {
		fprintf(stderr, "[ERROR]: Matrices don't have the same dimensions");
		return result;
	}

	for (int i = 0; i < m.rows; ++i)
		for (int j = 0; j < m.cols; ++j)
			result.elements[i][j] = substract
					? m.elements[i][j] - n.elements[i][j]
					: m.elements[i][j] + n.elements[i][j];
	
	return result;
}

Matrix mult_matrices(Matrix m, Matrix n) {
	Matrix result;
	fill_matrix(&result, m.rows, n.cols, 0, CONSTANT, 0);

	if (m.cols != n.rows) {
		fprintf(stderr, "[ERROR]: Matrices doesn't have compatible dimensions (%d != %d)", m.rows, n.cols);
		return result;
	}

	for (int i = 0; i < m.rows; ++i) {
		for (int j = 0; j < n.cols; ++j) {
			for (int k = 0; k < n.rows; ++k) {
				result.elements[i][j] += m.elements[i][k] * n.elements[k][j];
			}
		}
	}

	return result;
}

Matrix scalar_mult(Matrix m, int scalar)
{
	Matrix result;
	fill_matrix(&result, m.rows, m.cols, 0, CONSTANT, 0);

	for (int i = 0; i < m.rows; ++i)
		for (int j = 0; j < m.cols; ++j)
			result.elements[i][j] = m.elements[i][j] * scalar;

	return result;
}

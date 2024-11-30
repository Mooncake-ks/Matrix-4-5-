#include "matrix.h"

#include <iostream>

Matrix::Matrix() 
	: 
	m_row(0)
	, m_col(0)
	,m_matrix(nullptr) {
}

Matrix::Matrix(int row, int col) 
	: 
	m_row(row)
	, m_col(col) {
	m_matrix = new double* [row];
	for (int i = 0; i < row; ++i) {
		m_matrix[i] = new double[col];
		for (int j = 0; j < col; ++j) {
			m_matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other) 
	: 
	m_row(other.m_row)
	, m_col(other.m_col) {
	m_matrix = creature(m_row, m_col);
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	clear();
	m_row = other.m_row;
	m_col = other.m_col;
	m_matrix = creature(m_row, m_col);
	copy(other);
	return *this;
}
Matrix Matrix::operator*(const Matrix& other) const {
	Matrix test(m_row, other.m_col);

	if (m_col == other.m_row) {
		for (int i = 0; i < test.m_row; ++i) {
			for (int j = 0; j < test.m_col; ++j) {
				test.m_matrix[i][j] = 0;
			}

		}
		for (int i = 0; i < test.m_row; ++i) {
			for (int j = 0; j < test.m_col; ++j) {
				for (int k = 0; k < m_col; ++k) {
					test.m_matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
				}
			}
		}
	}
	else {
		std::cout << "Failed to multiply matrices\n";
	}
	return test;
}
Matrix Matrix::operator+(const Matrix& other) const {
	if (m_row != other.m_row || m_col != other.m_col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(m_row, m_col);

	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			result.m_matrix[i][j] = m_matrix[i][j] + other.m_matrix[i][j];
		}
	}

	return result;
}
Matrix Matrix::operator-(const Matrix& other) const {
	if (m_row != other.m_row || m_col != other.m_col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(m_row, m_col);

	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			result.m_matrix[i][j] = m_matrix[i][j] - other.m_matrix[i][j];
		}
	}

	return result;
}
bool Matrix::operator==(const Matrix& other) const {
	if (m_row != other.m_row || m_col != other.m_col) {
		return false;
	}

	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			if (m_matrix[i][j] != other.m_matrix[i][j]) {
				return false;
			}
		}
	}

	return true;
}
bool Matrix::operator!=(const Matrix& other) const {
	return !(*this==other);
}

double* Matrix::operator[](int index) {
	return m_matrix[index];
}
void Matrix::clear(Matrix& other) {
	for (int i = 0; i < other.m_row; ++i) {
		delete[] other.m_matrix[i];
	}
	delete[] other.m_matrix;
}
void Matrix::clear() {
	for (int i = 0; i < m_row; ++i) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}
double** Matrix::creature(int row, int col) {

	double** other = new double* [row];
	for (int i = 0; i < row; ++i) {
		other[i] = new double[col];
		for (int j = 0; j < col; ++j) {
			other[i][j] = 0;
		}
	}
	return other;
}
void Matrix::copy(const Matrix& other) {
	if (!(m_row == other.m_row && m_col == other.m_col)) {
		return;
	}
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			m_matrix[i][j] = other.m_matrix[i][j];
		}
	}
}

void Matrix::transponse() {
	if (m_row == m_col) {
		for (int i = 0; i < m_row; ++i) {
			for (int j = i; j < m_col; ++j) {
				if (!(i == j)) {
					int tmpValue = m_matrix[i][j];
					m_matrix[i][j] = m_matrix[j][i];
					m_matrix[j][i] = tmpValue;
				}
			}
		}

	}
	else {
		Matrix test(*this);
		clear(*this);
		m_matrix = creature(m_col, m_row);
		for (int i = 0; i < m_col; ++i) {
			for (int j = 0; j < m_row; ++j) {
				m_matrix[i][j] = test[i][j];
			}
		}
		int tmpValue = m_row;
		m_row = m_col;
		m_col = tmpValue;
	}
}
Matrix::~Matrix() {
	clear();
}

void Matrix::print() const {
	std::cout << "ROW: " << m_row << "\t" << "COL: " << m_col << "\n";
	for (int i = 0; i < m_row; ++i) {
		for (int j = 0; j < m_col; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
	int rows;
	int cols;
	std::cout << "Input rows: ";
	is >> rows;
	std::cout << "\nInput cols: ";
	is >> cols;
	matrix = Matrix(rows, cols);

	std::cout << "\nInput matrix: \n";
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			is >> matrix[i][j];
		}
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.m_row; ++i) {
		for (int j = 0; j < matrix.m_col; ++j) {
			os << matrix.m_matrix[i][j];
			os << " ";
		}
		os << "\n";
	}
	return os;
}
#include "matrix.h"

#include <iostream>

Matrix::Matrix() 
	: 
	row(0)
	,col(0)
	,ptrarr(nullptr) {
}

Matrix::Matrix(int row, int col) 
	: 
	row(row)
	,col(col) {
	ptrarr = new double* [row];
	for (int i = 0; i < row; ++i) {
		ptrarr[i] = new double[col];
		for (int j = 0; j < col; ++j) {
			ptrarr[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& other) 
	: 
	row(other.row)
	,col(other.col) {
	ptrarr = creature(row, col);
	copy(*this, other);
}

Matrix& Matrix::operator=(const Matrix& other) {
	clear();
	row = other.row;
	col = other.col;
	ptrarr = creature(row, col);
	copy(*this, other);
	return *this;
}
Matrix Matrix::operator*(const Matrix& other) const {
	int sizerow = row;
	int sizecol = other.col;
	Matrix test(sizerow, sizecol);

	if (col == other.row) {
		for (int i = 0; i < sizerow; ++i) {
			for (int j = 0; j < sizecol; ++j) {
				test.ptrarr[i][j] = 0;
			}

		}
		for (int i = 0; i < sizerow; ++i) {
			for (int j = 0; j < sizecol; ++j) {
				for (int k = 0; k < col; ++k) {
					test.ptrarr[i][j] += ptrarr[i][k] * other.ptrarr[k][j];
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
	if (row != other.row || col != other.col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(row, col);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			result.ptrarr[i][j] = ptrarr[i][j] + other.ptrarr[i][j];
		}
	}

	return result;
}
Matrix Matrix::operator-(const Matrix& other) const {
	if (row != other.row || col != other.col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(row, col);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			result.ptrarr[i][j] = ptrarr[i][j] - other.ptrarr[i][j];
		}
	}

	return result;
}
bool Matrix::operator==(const Matrix& other) const {
	if (row != other.row || col != other.col) {
		return false;
	}

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (ptrarr[i][j] != other.ptrarr[i][j]) {
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
	return ptrarr[index];
}
void Matrix::clear(Matrix& other) {
	for (int i = 0; i < other.row; ++i) {
		delete[] other.ptrarr[i];
	}
	delete[] other.ptrarr;
}
void Matrix::clear() {
	for (int i = 0; i < row; ++i) {
		delete[] ptrarr[i];
	}
	delete[] ptrarr;
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
void Matrix::copy(Matrix& other, const Matrix& other_2) {
	if (!(other.row == other_2.row && other.col == other_2.col)) {
		return;
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			other.ptrarr[i][j] = other_2.ptrarr[i][j];
		}
	}
}

void Matrix::transpose() {
	if (row == col) {
		for (int i = 0; i < row; ++i) {
			for (int j = i; j < col; ++j) {
				if (!(i == j)) {
					int tmpValue = ptrarr[i][j];
					ptrarr[i][j] = ptrarr[j][i];
					ptrarr[j][i] = tmpValue;
				}
			}
		}

	}
	else {
		Matrix test(*this);
		clear(*this);
		ptrarr = creature(col, row);
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j) {
				ptrarr[i][j] = test[i][j];
			}
		}
		int tmpValue = row;
		row = col;
		col = tmpValue;
	}
}
Matrix::~Matrix() {
	clear();
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
	int rows, cols;
	is >> rows;
	char c;
	is >> c;
	is >> cols;
	is >> c;
	matrix = Matrix(rows, cols);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			is >> matrix[i][j];
			is >> c;
		}
	}

	return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
	for (int i = 0; i < matrix.row; ++i) {
		for (int j = 0; j < matrix.col; ++j) {
			os << matrix.ptrarr[i][j];
			os << " ";
		}
		os << "\n";
	}
	return os;
}
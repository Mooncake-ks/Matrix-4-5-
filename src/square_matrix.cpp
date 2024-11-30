#include "square_matrix.h"

SquareMatrix::SquareMatrix()
	:
	m_size(0)
	, m_matrix(nullptr) {
}

SquareMatrix::SquareMatrix(int size) 
	:
	m_size(size) {
	m_matrix = new double* [m_size];
	for (int i = 0; i < m_size; ++i) {
		m_matrix[i] = new double[m_size];
		for (int j = 0; j < m_size; ++j) {
			m_matrix[i][j] = 0;
		}
	}
}

SquareMatrix::SquareMatrix(const SquareMatrix& other)
	:
	m_size(other.m_size) {
	m_matrix = creature(m_size, m_size);
	copy(other);
}

double SquareMatrix::determinantGauss() const {
	if (m_size == 0) {
		return 1.0;
	}
	if (m_size == 1) {
		return m_matrix[0][0]; // matrix 1x1
	}

	double det = 1.0;
	SquareMatrix matrix(*this);
	for (int i = 0; i < m_size; ++i) {
		// find max el in col
		int maxRow = i;
		for (int k = i + 1; k < m_size; ++k) {
			if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
				maxRow = k;
			}
		}

		// Rearranging strings (if necessary)
		if (maxRow != i) {
			for (int j = 0; j < m_size; ++j) {
				double tmpValue = matrix[maxRow][j];
				matrix[maxRow][j] = matrix[i][j];
				matrix[i][j] = tmpValue;
			}
			det *= -1.0;
		}

		// If the diagonal element is zero, the determinant is zero
		if (matrix[i][i] == 0.0) {
			return 0.0;
		}

		// Making it look triangular
		det *= matrix[i][i];
		for (int k = i + 1; k < m_size; ++k) {
			double factor = matrix[k][i] / matrix[i][i];
			for (int j = i; j < m_size; ++j) {
				matrix[k][j] -= factor * matrix[i][j];
			}
		}
	}
	return det;
}

void SquareMatrix::copy(const SquareMatrix& other) {
	if (!(m_size == other.m_size)) {
		return;
	}
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			m_matrix[i][j] = other.m_matrix[i][j];
		}
	}
}

void SquareMatrix::identityMatrix() {
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			m_matrix[i][j] = (i == j) ? 1.0 : 0.0;
		}
	}
}

void SquareMatrix::matrixPower(int power) {
	if (power < 0) {
		throw std::invalid_argument("Power must be non-negative.");
	}
	else if (power == 0) {
		identityMatrix();
		return;
	}
	else if (power == 1) {
		return;
	}
	SquareMatrix tmpMatrix(*this);
	for (int i = 1; i < power; ++i) {
		tmpMatrix = (*this) * tmpMatrix;
	}
	*this = tmpMatrix;
}

double SquareMatrix::firstNorm() const {
	if (m_size == 0) {
		return 0.0;
	}
	double maxColSum = 0.0;
	for (int j = 0; j < m_size; ++j) {
		double colSum = 0.0;
		for (int i = 0; i < m_size; ++i) {
			colSum += std::abs(m_matrix[i][j]);
		}
		maxColSum = maxColSum > colSum ? maxColSum : colSum;
	}
	return maxColSum;
}

void SquareMatrix::clear() {
	for (int i = 0; i < m_size; ++i) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}
void SquareMatrix::transponse() {
	for (int i = 0; i < m_size; ++i) {
		for (int j = i + 1; j < m_size; ++j) {
			double tempValue = m_matrix[i][j];
			m_matrix[i][j] = m_matrix[j][i];
			m_matrix[j][i] = tempValue;
		}
	}
}

void SquareMatrix::print() const {
	std::cout << "SIZE: " << m_size << "\n";
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

double* SquareMatrix::operator[](int index) {
	return m_matrix[index];
}

SquareMatrix SquareMatrix::operator *(const SquareMatrix& other) {
	SquareMatrix matrix(m_size);
	for (int i = 0; i < m_size; ++i) {
		for (int j = 0; j < m_size; ++j) {
			matrix[i][j] = 0;
			for (int k = 0; k < m_size; ++k) {
				matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
			}
		}
	}
	return matrix;
}

SquareMatrix& SquareMatrix::operator =(const SquareMatrix& other) {
	clear();
	m_size = other.m_size;
	m_matrix = creature(m_size, m_size);
	copy(other);
	return *this;
}

SquareMatrix::~SquareMatrix() {
	clear();
}

std::istream& operator>>(std::istream& is, SquareMatrix& matrix) {
	int size;
	std::cout << "Input siz: ";
	is >> size;
	matrix = SquareMatrix(size);

	std::cout << "\nInput matrix: \n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			is >> matrix[i][j];
		}
	}
	return is;
}

std::ostream& operator<<(std::ostream& os, const SquareMatrix& matrix) {
	for (int i = 0; i < matrix.m_size; ++i) {
		for (int j = 0; j < matrix.m_size; ++j) {
			os << matrix.m_matrix[i][j];
			os << " ";
		}
		os << "\n";
	}
	return os;
}
#include "Matrix.h"

Matrix::Matrix() :row{ 0 }, col{ 0 }, ptrarr{ nullptr } {}

Matrix::Matrix(int row, int col) : row{ row }, col{ col }
{
	ptrarr = new double* [row];
	for (int i = 0; i < row; i++)
	{
		ptrarr[i] = new double[col];
	}
}

Matrix::Matrix(const Matrix& other) : row{ other.row }, col{ other.col }
{
	this->ptrarr = creature(row, col);
	copy(*this, other);
}

Matrix::Matrix(const std::initializer_list< std::initializer_list<double>>& list)
{
	row = list.size();
	col = (list.begin())->size();
	ptrarr = creature(row, col);
	int i = 0;
	for (auto el = list.begin(); el != list.end(); el++, i++)
	{
		ptrarr[i] = new double[col];
		std::copy(el->begin(), el->end(), ptrarr[i]);
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	cleer(*this);
	this->row = other.row;
	this->col = other.col;
	this->ptrarr = creature(row, col);
	copy(*this, other);
	return *this;
}
Matrix Matrix::operator*(const Matrix& other)const
{
	int x = 0, sizerow = 0, sizecol = 0;
	sizerow = this->row;
	sizecol = other.col;
	Matrix test(sizerow, sizecol);

	if (this->col == other.row)
	{
		for (int i = 0; i < sizerow; i++)
		{
			for (int j = 0; j < sizecol; j++)
			{
				test.ptrarr[i][j] = 0;
			}

		}
		for (int i = 0; i < sizerow; i++)
		{
			for (int j = 0; j < sizecol; j++)
			{
				for (int k = 0; k < this->col; k++)
				{
					test.ptrarr[i][j] += this->ptrarr[i][k] * other.ptrarr[k][j];
				}
			}
		}
	}
	else
		std::cout << "Failed to multiply matrices\n";
	return test;
}
Matrix Matrix::operator+(const Matrix& other)const {
	if (this->row != other.row || this->col != other.col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(this->row, this->col);

	for (int i = 0; i < this->row; ++i) {
		for (int j = 0; j < this->col; ++j) {
			result.ptrarr[i][j] = this->ptrarr[i][j] + other.ptrarr[i][j];
		}
	}

	return result;
}
Matrix Matrix::operator-(const Matrix& other)const {
	if (this->row != other.row || this->col != other.col) {
		throw "Matrices have different dimensions";
	}

	Matrix result(this->row, this->col);

	for (int i = 0; i < this->row; ++i) {
		for (int j = 0; j < this->col; ++j) {
			result.ptrarr[i][j] = this->ptrarr[i][j] - other.ptrarr[i][j];
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

double* Matrix::operator[](int index)
{
	return ptrarr[index];
}
void Matrix::cleer(Matrix& other)
{
	for (int i = 0; i < row; i++)
	{
		delete[] other.ptrarr[i];
	}
	delete[] other.ptrarr;
}
double** Matrix::creature(int row, int col)
{

	double** other = new double* [row];
	for (int i = 0; i < row; i++)
	{
		other[i] = new double[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			other[i][j] = 0;
		}
	}
	return other;
}
void Matrix::copy(Matrix& other, const Matrix& other_2)
{
	if (!(other.row == other_2.row && other.col == other_2.col))
	{
		return;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			other.ptrarr[i][j] = other_2.ptrarr[i][j];
		}
	}
}

void Matrix::transpose()
{
	if (row == col)
	{
		int x = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = i; j < col; j++)
			{
				if (!(i == j))
				{
					x = ptrarr[i][j];
					ptrarr[i][j] = ptrarr[j][i];
					ptrarr[j][i] = x;
				}
			}
		}

	}
	else
	{
		double** test = creature(this->col, this->row);
		for (int i = 0; i < this->col; i++)
		{
			for (int j = 0; j < this->row; j++)
			{

				test[i][j] = ptrarr[j][i];
			}
		}
		cleer(*this);
		this->ptrarr = creature(col, row);
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{

				ptrarr[i][j] = test[i][j];


			}
		}
		std::swap(row, col);

	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < row; i++)
	{
		delete[] ptrarr[i];
	}
	delete[]ptrarr;
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
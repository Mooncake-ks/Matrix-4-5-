#pragma once
#include <iostream>
class Matrix {
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& other);

	Matrix& operator =(const Matrix& other);
	Matrix operator *(const Matrix& other)const;
	Matrix operator+(const Matrix& other)const;
	Matrix operator-(const Matrix& other)const;
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
	double* operator [](int index);

	void clear(Matrix& other);
	void clear();
	double** creature(int row, int col);
	void copy(Matrix& other, const Matrix& other_2);
	void transpose();

	~Matrix();
	void print();

	friend std::istream& operator>>(std::istream& is, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
private:
	int row, col;
	double** ptrarr;
};


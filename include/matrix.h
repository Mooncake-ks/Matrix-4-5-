#pragma once
#include <iostream>
class Matrix {
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& other);

	Matrix& operator =(const Matrix& other);
	Matrix operator *(const Matrix& other) const;
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
	double* operator [](int index);

	virtual void transponse();
	virtual void print() const;
	virtual ~Matrix();

	friend std::istream& operator>>(std::istream& is, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
protected:
	double** creature(int row, int col);

	virtual void clear();
private:
	void copy(const Matrix& other);
	void clear(Matrix& other);
private:
	int row;
	int col;
	double** m_matrix;
};


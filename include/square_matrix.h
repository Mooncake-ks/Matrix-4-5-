#pragma once
#include "matrix.h"

class SquareMatrix : public Matrix {
public:
	SquareMatrix();
	SquareMatrix(int size);
	SquareMatrix(const SquareMatrix& other);

	void matrixPower(int power);
	double determinantGauss() const;
	double firstNorm() const;

	SquareMatrix& operator=(const SquareMatrix& other);
	double* operator [](int index);
	SquareMatrix operator *(const SquareMatrix& other);
	~SquareMatrix() override;

	virtual void transponse() override;
	virtual void print() const override;

	friend std::istream& operator>>(std::istream& is, SquareMatrix& matrix);
	friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& matrix);
private:
	void copy(const SquareMatrix& other);
	void identityMatrix();

	virtual void clear() override;
private:
	int m_size;
	double** m_matrix;
};


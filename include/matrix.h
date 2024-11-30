#pragma once

class Matrix
{
	public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& other);
	Matrix(const std::initializer_list<std::initializer_list<double>>& list);

	Matrix& operator =(const Matrix& other);
	Matrix operator *(const Matrix& other)const;
	Matrix operator+(const Matrix& other)const;
	Matrix operator-(const Matrix& other)const;
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;
	double* operator [](int index);

	void cleer(Matrix& other);
	double** creature(int row, int col);
	void copy(Matrix& other, const Matrix& other_2);
	void transpose();

	~Matrix();
	void print() {
		std::cout << row << "\t" << col << "\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				std::cout << ptrarr[i][j] << " ";
			}
			std::cout << std::endl;
		}


	}

	friend std::istream& operator>>(std::istream& is, Matrix& matrix);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
private:
	int row, col;
	double** ptrarr;
};


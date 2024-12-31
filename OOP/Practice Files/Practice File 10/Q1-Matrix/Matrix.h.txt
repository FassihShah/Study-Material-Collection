#ifndef MATRIX_H
#define MATRIX_H
using namespace std;
class Matrix
{
	int** data;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int, int);
	~Matrix();
	Matrix(const Matrix&);
	int getRows()const;
	int getColums()const;
	int& at(int, int);
	const int& at(int, int) const;
	void display() const;
	Matrix transpose() const;
	Matrix add( const Matrix &) const;
	Matrix multiply(const Matrix&) const;
	void reSize(int, int);
};
#endif
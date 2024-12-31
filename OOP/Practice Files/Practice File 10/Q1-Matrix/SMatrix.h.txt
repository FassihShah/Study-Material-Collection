#ifndef SMATRIX_H
#define SMATRIX_H
#include "Matrix.h"
using namespace std;
class SMatrix
{
	Matrix mat;
	int size;
	SMatrix(const Matrix& );
public:
	SMatrix(int = 0);
	SMatrix(const SMatrix&);
	~SMatrix();
	int& at(int, int);
	const int& at(int, int) const;
	int getRows()const;
	int getColums()const;
	void display() const;
	SMatrix transpose() const;
	SMatrix add(const SMatrix&) const;
	SMatrix multiply(const SMatrix&) const;
	void reSize(int);
};

#endif

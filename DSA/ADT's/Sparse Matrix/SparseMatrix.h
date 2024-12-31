#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H
#include"Element.h"
class SparseMatrix
{
	Element* data;
	int NOE;
	int noOfRows;
	int noOfCols;
	bool isUniqueCell(int, int);
	void reSize();
public:
	//SparseMatrix();
	SparseMatrix(int, int);
	~SparseMatrix();
	int getIndexValue(int, int) const;
	void insert(int, int, int);
	SparseMatrix add(const SparseMatrix&) const;
	SparseMatrix multiply(const SparseMatrix& other) const;
	SparseMatrix transpose() const;
	void print();
};
#endif
#include<iostream>
#include"SparseMatrix.h"
using namespace std;
SparseMatrix::SparseMatrix(int r, int c)
{
	noOfRows = r;
	noOfCols = c;
	NOE = 0;
	data = nullptr;
}
int SparseMatrix::getIndexValue(int j, int k) const
{
	for (int i = 0; i < NOE; i++)
	{
		if (data[i].getRow() == j && data[i].getColumn() == k)
			return data[i].getValue();
	}
	return 0;
}
SparseMatrix::~SparseMatrix()
{
	if (data)
		delete[] data;
	noOfRows = 0;
	noOfCols = 0;
	NOE = 0;
	data = nullptr;
}
void SparseMatrix::reSize()
{
	Element* t = new Element[NOE + 1]; 
	for (int i = 0; i < NOE; i++)
	{
		t[i] = data[i];
	}
	if(data)
		delete[] data;
	data = t;
	t = nullptr;
}
void SparseMatrix::insert(int r, int c, int v)
{
	if (r < 0 || r >= noOfRows || c < 0 || c >= noOfCols)
		return;
	if (isUniqueCell(r, c))
	{
		reSize();
		data[NOE].setRow(r);
		data[NOE].setColumn(c);
		data[NOE].setValue(v);
		NOE++;
	}
	else
	{
		for (int i = 0; i < NOE; i++)
		{
			if (data[i].getRow() == r && data[i].getColumn() == c)
				data[i].setValue(v);
		}
	}
}
void SparseMatrix::print()
{
	bool status = false;
	for (int i = 0; i < noOfRows; i++)
	{
		for (int j = 0; j < noOfCols; j++)
		{
			cout << getIndexValue(i, j) << " ";
		}
		cout << "\n";
	}
}
SparseMatrix SparseMatrix::add(const SparseMatrix & other) const
{
	if (noOfRows != other.noOfRows || noOfCols != other.noOfCols)
	{
		cout << "Cannot be added!";
		exit(0);
	}
	SparseMatrix result(noOfRows,noOfCols);
	for (int i = 0; i < NOE; i++)
	{
		result.insert(data[i].getRow(), data[i].getColumn(), data[i].getValue());
	}
	for (int i = 0; i < other.NOE; i++)
	{
		result.insert(other.data[i].getRow(), other.data[i].getColumn(), other.data[i].getValue() + getIndexValue(other.data[i].getRow(), other.data[i].getColumn()));
	}
	return result;
}
SparseMatrix SparseMatrix::multiply(const SparseMatrix& other) const
{
	if (noOfCols != other.noOfRows)
	{
		cout << "Cannot be multiplied!";
		exit(0);
	}
	SparseMatrix result(noOfRows, other.noOfCols);
	for (int i = 0; i < noOfRows; i++)
	{
		for (int j = 0; j < other.noOfCols; j++)
		{
			int val = 0;
			for (int k = 0; k < other.noOfRows; k++)
			{
				val = val + (getIndexValue(i, k) * other.getIndexValue(k, j));
			}
			if (val != 0)
			{
				result.insert(i, j, val);
			}
		}
	}
	return result;
}
SparseMatrix SparseMatrix::transpose() const
{
	SparseMatrix result(noOfCols, noOfRows);
	for (int i = 0; i < NOE; i++)
	{
		result.insert(data[i].getColumn(), data[i].getRow(), data[i].getValue());
	}
	return result;
}
bool SparseMatrix::isUniqueCell(int r, int c)
{
	for (int i = 0; i < NOE; i++)
	{
		if (data[i].getRow() == r && data[i].getColumn() == c)
			return false;
	}
	return true;
}
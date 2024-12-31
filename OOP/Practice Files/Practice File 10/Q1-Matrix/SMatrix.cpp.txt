#include<iostream>
#include"SMatrix.h"
using namespace std;
SMatrix::SMatrix(int s):mat(s,s)
{
	size = s;
}
SMatrix::SMatrix(const SMatrix& ref):mat(ref.mat)
{
	size = ref.size;
}
SMatrix::SMatrix(const Matrix& m):mat(m)
{
	size = m.getColums();
}
SMatrix::~SMatrix()
{
	mat.~Matrix();
	size = 0;
}
int& SMatrix::at(int r, int c)
{
	return mat.at(r, c);
}
const int& SMatrix::at(int r,int c) const
{
	return mat.at(r, c);
}
int SMatrix::getRows() const
{
	return size;
}
int SMatrix::getColums() const
{
	return size;
}
void SMatrix::display() const
{
	mat.display();
}
SMatrix SMatrix::transpose() const
{
	SMatrix temp(mat.transpose());
	return temp;
}
SMatrix SMatrix::add(const SMatrix& ref) const
{
	SMatrix temp(mat.add(ref.mat));
	return temp;
}
SMatrix SMatrix::multiply(const SMatrix& ref) const
{
	SMatrix temp(mat.multiply(ref.mat));
	return temp;
}
void SMatrix::reSize(int s)
{
	mat.reSize(s, s);
	size = s;
}
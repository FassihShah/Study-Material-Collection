#include"OrderedPair.h"
OrderedPair::OrderedPair(int n, int m)
{
	a = n;
	b = m;
}
int& OrderedPair::atA()
{
	return a;
}
int& OrderedPair::atB()
{
	return b;
}
const int& OrderedPair::atA() const
{
	return a;
}
const int& OrderedPair::atB() const
{
	return b;
}
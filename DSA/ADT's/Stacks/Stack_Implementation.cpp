#include"Stack.cpp"
struct Point
{
	int row;
	int col;
	Point(int r, int c) :row(r), col(c)
	{}
	Point() :row(0), col(0) {}
};
template class Stack<int>;
template class Stack<char>; 
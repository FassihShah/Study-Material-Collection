#ifndef ELEMENT_H
#define ELEMENT_H
class Element
{
	int row;
	int column;
	int value;
public:
	Element(int, int, int);
	Element();
	void setRow(int);
	void setColumn(int);
	void setValue(int);
	int getRow();
	int getColumn();
	int getValue();
};
#endif
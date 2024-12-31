#include"Element.h"
Element::Element(int r, int c, int v)
{
	row = r;
	column = c;
	value = v;
}
Element::Element()
{
	row = 0;
	column = 0;
}
void Element::setRow(int r)
{
	if (r >= 0)
		row = r;
}
void Element::setColumn(int c)
{
	if (c >= 0)
		column = c;
}
void Element::setValue(int v)
{
	value = v;
}
int Element::getRow()
{
	return row;
}
int Element::getColumn()
{
	return column;
}
int Element::getValue()
{
	return value;
}
#include"CD.h"
CD::CD()
{
	capacity = 0;
}
CD::CD(String t, int c) :Media(t)
{
	capacity = c;
}
void CD::display()
{
	cout << "\n\nCD title         : " << getTitle();
	cout << "\nCD capacity(MBs) : " << capacity;
}
#include"Magazine.h"
Magazine::Magazine()
{
	year = 2000;
}
Magazine::Magazine(String t, String m, int y):Media(t)
{
	month = m;
	year = y;
}
Magazine::~Magazine()
{
	month.~String();
}
void Magazine::display()
{
	cout << "\n\nMagazine Title    : " << getTitle();
	cout << "\nPublication Month : " << month;
	cout << "\nPublication Year  : " << year;
}
int Magazine::getYear()
{
	return year;
}
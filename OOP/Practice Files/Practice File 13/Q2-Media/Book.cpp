#include"Book.h"
Book::Book()
{

}
Book::Book(String t, String a, String n):Media(t)
{
	author = a;
	ISBN = n;
}
Book::~Book()
{
	ISBN.~String();
}
void Book::display()
{
	cout << "\n\nBook Title  : " << getTitle();
	cout << "\nAuthor Name : " << author;
	cout << "\nISBN        : " << ISBN;
}
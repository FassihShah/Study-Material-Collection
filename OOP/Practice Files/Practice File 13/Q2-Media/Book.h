#ifndef BOOK_H
#define BOOK_H
#include"Media.h"
class Book:public Media
{
	String author;
	String ISBN;
public:
	Book();
	Book(String, String, String);
	void display();
	~Book();
};
#endif
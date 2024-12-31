#ifndef MAGAZINE_H
#define MAGAZINE_H
#include"Media.h"
class Magazine :public Media
{
	String month;
	int year;
public:
	Magazine();
	Magazine(String, String, int);
	void display();
	int getYear();
	~Magazine();
};
#endif
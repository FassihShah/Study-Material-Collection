#ifndef CD_H
#define CD_H
#include"Media.h"
class CD :public Media
{
	int capacity;
public:
	CD();
	CD(String, int);
	void display();
};
#endif
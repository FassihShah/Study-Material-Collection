#ifndef MEDIA_H
#define MEDIA_H
#include"String.h"
class Media
{
	String title;
protected:
	void setTitle(String);
	String getTitle();
public:
	Media();
	Media(String);
	virtual void display() = 0;
	virtual ~Media() = 0;
};
#endif
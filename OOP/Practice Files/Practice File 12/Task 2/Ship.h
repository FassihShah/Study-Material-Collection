#pragma once
#include"String.h"
class Ship
{
	String name;
	String builtYear;
public:
	Ship(String n, String y);
	void setName(String n);
	String getName();
	String getYear();
	void setYear(String y);
	virtual void print();
};
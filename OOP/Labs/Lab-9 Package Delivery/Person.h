#ifndef PERSON_H
#define PERSON_H
#include"String.h"
class Person
{
	String name;
	String address;
	String city;
	String state;
	int zip;
public:
	Person(String, String, String, String, int);
	String getName();
	String getAddress();
	String getCity();
	String getState();
	int getZip();
};

#endif

#include"Person.h"
Person::Person(String n, String ad, String c, String st, int z):name(n),address(ad),city(c),state(st)
{
	zip = z;
}
String Person::getName()
{
	return name;
}
String Person::getAddress()
{
	return address;
}
String Person::getCity()
{
	return city;
}
String Person::getState()
{
	return state;
}
int Person::getZip()
{
	return zip;
}
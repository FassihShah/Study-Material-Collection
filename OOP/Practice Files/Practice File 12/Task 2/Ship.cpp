#include<iostream>
#include"Ship.h"
using namespace std;
Ship::Ship(String n, String y):name(n),builtYear(y)
{
	
}
void Ship::setName(String n)
{
	name = n;
}
String Ship::getName()
{
	return name;
}
String Ship::getYear()
{
	return builtYear;
}
void Ship::setYear(String y)
{
	builtYear = y;
}
void Ship::print()
{
	cout << "\nName : " << name << "\nBuilt Year : " << builtYear;
}
#pragma once
#include"Ship.h"
class CruiseShip:public Ship
{
	int maxPassengers;
public:
	CruiseShip(String, String, int);
	void setPassengers(int);
	int getPassengers();
	void print();
};
#pragma once
#include"Ship.h"
class BattleShip :public Ship
{
	int noOfMissiles;
public:
	BattleShip(String, String, int);
	void setMissiles(int);
	int getMissiles();
	void print();
};
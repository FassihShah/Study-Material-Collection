#include"BattleShip.h"
BattleShip::BattleShip(String n, String y, int m):Ship(n,y)
{
	setMissiles(m);
}
void BattleShip::setMissiles(int m)
{
	noOfMissiles = (m >= 0 ? m : 0);
}
int BattleShip::getMissiles()
{
	return noOfMissiles;
}
void BattleShip::print()
{
	cout << "\nName : " << getName() << "\nNumber of Missiles : " << noOfMissiles;
}
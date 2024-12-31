#include"String.h"
#include"TollPlaza.h"
int TollPlaza::_carToll = 20;
int TollPlaza::_bikeToll = 10;
int TollPlaza::_busToll = 50;
int TollPlaza::_heavyDutyTruckToll = 100;
int TollPlaza::_lightDutyTruckToll = 70;
TollPlaza::TollPlaza(int id, String add, long int mt):MAX_TOLL(mt),address(add)
{
	tollPlazaId = id;
	collectedToll = 0;
}
void TollPlaza::resetTollPlaza()
{
	collectedToll = 0;
}
void TollPlaza::chargeVehicle(int vehicleType)
{
	if (vehicleType == _CAR)
	{
		collectedToll = collectedToll + _carToll;
	}
	else if (vehicleType == _BIKE)
	{
		collectedToll = collectedToll + _bikeToll;
	}
	else if (vehicleType == _BUS)
	{
		collectedToll = collectedToll + _busToll;
	}
	else if (vehicleType == _HEAVY_DUTY_TRUCK)
	{
		collectedToll = collectedToll + _heavyDutyTruckToll;
	}
	else if (vehicleType == _LIGHT_DUTY_TRUCK)
	{
		collectedToll = collectedToll + _lightDutyTruckToll;
	}
}
long int TollPlaza::getCollectedTollToday() const
{
	return collectedToll;
}
long int TollPlaza::getMaxToll() const
{
	return MAX_TOLL;
}
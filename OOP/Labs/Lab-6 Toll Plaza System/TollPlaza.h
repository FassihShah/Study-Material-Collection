#ifndef TOLL_PLAZA_H
#define TOLL_PLAZA_H
#include "String.h"
class TollPlaza
{
	static const int _CAR = 1;
	static const int _BIKE = 2;
	static const int _BUS = 3;
	static const int _HEAVY_DUTY_TRUCK = 4;
	static const int _LIGHT_DUTY_TRUCK = 5;
	static int _carToll;
	static int _bikeToll;
	static int _busToll;
	static int _heavyDutyTruckToll;
	static int _lightDutyTruckToll;
	long int collectedToll;
	const long int MAX_TOLL;
	int tollPlazaId;
	String address;
public:
	TollPlaza(int, String, long int);
	void resetTollPlaza();
	void chargeVehicle(int);
	long int getCollectedTollToday() const;
	long int getMaxToll() const;
};
#endif
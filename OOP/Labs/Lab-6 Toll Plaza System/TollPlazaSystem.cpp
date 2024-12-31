#include<iostream>
#include"TollPlazaSystem.h"
#include"TollPlaza.h"
using namespace std;
void TollPlazaSystem::startApplication()
{
	int id;
	String add;
	long int maxToll;
	cout << "Enter toll plaza address : ";
	add.input();
	cout << "Enter toll plaza Id No. : ";
	cin >> id;
	cout << "Set maximum toll : ";
	cin >> maxToll;
	TollPlaza t(id,add,maxToll);
	int veh;
	do
	{
		cout << "\n\t\tCar = 1" << "\n\t\tBike = 2" << "\n\t\tBus = 3" << "\n\t\tHeavy Duty Truck = 4" << "\n\t\tLight Duty Truck = 5";
		cout << "\n\t\tTo reset today data = 6" << "\n\t\tTo see collected toll goal today = 7" <<"\n\t\tTo see maximum toll = 8" << "\n\t\tTo close Toll Plaza = 0";
		cout << "\nEnter : ";
		cin >> veh;
		if (veh == 6)
			t.resetTollPlaza();
		else if (veh == 7)
			cout << "Collected toll today : " << t.getCollectedTollToday();
		else if(veh==8)
			cout << "Maximum toll goal : " << t.getMaxToll();
		else
			t.chargeVehicle(veh);
		if (t.getCollectedTollToday() >= t.getMaxToll())
			cout << "\n Toll Plaza successfully attained its today's goal amount!";
	}
	while (veh != 0);
}

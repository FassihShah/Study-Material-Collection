#include"Customer.h"
Customer::Customer(String n, int h, int s)
{
	name = n;
	hours = h;
	spaceUsed = s;
}
double Customer::computeBill()
{
	if (spaceUsed > 1)
	{
		cout << "\nCustomer is not valid option because used disk space is greater than 1 MB";
	}
	if (hours > 4)
		return (10 + ((hours - 4) * 4));
	else
		return 10;
}
int Customer::getHours()
{
	return hours;
}
int Customer::getSpaceUsed()
{
	return spaceUsed;
}
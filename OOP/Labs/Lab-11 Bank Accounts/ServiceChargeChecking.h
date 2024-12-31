#ifndef SERVICE_CHARGE_CHECKING_H
#define SERVICE_CHARGE_CHECKING_H
#include"CheckingAccount.h"
class ServiceChargeChecking:public CheckingAccount
{
	double serviceCharges;
	const int checksLimit;
	int checksUsed;
public:
	ServiceChargeChecking(String, String, double, double, double);
	void writeCheck(double);
	void createMonthlyStatement();
};


#endif
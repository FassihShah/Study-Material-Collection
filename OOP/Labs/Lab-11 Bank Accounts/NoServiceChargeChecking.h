#ifndef NO_SERVICE_CHARGE_CHECKING_H
#define NO_SERVICE_CHARGE_CHECKING_H
#include"CheckingAccount.h"
class NoServiceChargeChecking:public CheckingAccount
{
	double minBalance;
	double interestRate;
public:
	NoServiceChargeChecking(String, String, double, double, double);
	void writeCheck(double);
	void createMonthlyStatement();
};
#endif
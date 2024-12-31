#ifndef HIGH_INTEREST_SAVINGS_H
#define HIGH_INTEREST_SAVINGS_H
#include"SavingsAccount.h"
class HighInterestSavings :public SavingsAccount
{
	double minBalance;
public:
	HighInterestSavings(String, String, double, double, double);
};
#endif
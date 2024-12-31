#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include"BankAccount.h"
class SavingsAccount :public BankAccount
{
	double interestRate;
public:
	SavingsAccount(String, String, double, double);
	void createMonthlyStatement();
};
#endif
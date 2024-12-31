#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H
#include"BankAccount.h"
class CheckingAccount:public BankAccount
{

public:
	BankAccount::BankAccount;
	virtual void writeCheck(double) = 0;
	void createMonthlyStatement();
};
#endif
#pragma once
#include"Account.h"
class LoanAccount:public Account
{
public:
	using Account::Account;
	void deposit(double);
	double calculateInterest(int);
};
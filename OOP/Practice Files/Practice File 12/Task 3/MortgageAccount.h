#pragma once
#include"Account.h"
class MortgageAccount :public Account
{
public:
	using Account::Account;
	void deposit(double);
	double calculateInterest(int);
};
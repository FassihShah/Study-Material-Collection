#pragma once
#include"Account.h"
class DepositAccount:public Account
{
public:
	using Account::Account;
	void deposit(double);
	void withDraw(double);
	double calculateInterest(int);
};
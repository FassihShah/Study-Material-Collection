#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include"String.h"
#include"Array.h"
class BankAccount
{
	String name;
	String accountNumber;
	double balance;
protected:
	double getBalance();
	Array bal;
	Array withDrawn;
	int count;
public:
	BankAccount(String, String, double);
	void deposit(double);
	void withDraw(double);
	virtual void createMonthlyStatement() = 0;
};
#endif
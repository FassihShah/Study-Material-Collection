#pragma once
class Account
{
public:
	enum CustomerType { INDIVIDUAL, COMPANY };
	Account(CustomerType, double, double);
	virtual double calculateInterest(int);
protected:
	void credit(double amount);
	bool debit(double amount);
	double balance;
	CustomerType customer;
	double interestRate;
};
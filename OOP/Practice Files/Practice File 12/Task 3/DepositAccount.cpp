#include"DepositAccount.h"
#include<iostream>
void DepositAccount::withDraw(double amount)
{
	if (!debit(amount))
		std::cout << "\nWithdraw amount exceeded account balance";
}
void DepositAccount::deposit(double amount)
{
	credit(amount);
}
double DepositAccount::calculateInterest(int months)
{
	if (balance < 1000)
		return balance;
	return balance * (1 + interestRate * months);
}
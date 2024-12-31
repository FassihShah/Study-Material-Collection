#include"Account.h"
Account::Account(CustomerType c, double b, double r)
{
	customer = c;
	balance = (b >= 0 ? b : 0);
	interestRate = (r >= 0 ? r : 0);
}
void Account::credit(double amount)
{
	if (amount > 0)
		balance += amount;
}
bool Account::debit(double amount)
{
	if (amount > 0)
	{
		if (amount <= balance)
		{
			balance -= amount;
			return true;
		}
		return false;
	}
	return false;
}
double Account::calculateInterest(int months)
{
	return balance * (1 + interestRate * months);
}
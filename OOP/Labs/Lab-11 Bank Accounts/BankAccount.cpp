#include"BankAccount.h"
BankAccount::BankAccount(String n, String a, double b):bal(30), withDrawn(30)
{
	name = n;
	accountNumber = a;
	balance = (b >= 0 ? b : 0);
	count = 0;
}
void BankAccount::deposit(double amount)
{
	if (amount > 0)
	{
		balance += amount;
		bal[count] = getBalance();
		withDrawn[count] = amount;
		count++;
	}
}
double BankAccount::getBalance()
{
	return balance;
}
void BankAccount::withDraw(double amount)
{
	if (amount > 0)
	{
		if (amount <= balance)
		{
			bal[count] = getBalance();
			withDrawn[count] = -1*amount;
			balance -= amount;
		}
	}
	count++;
}
void BankAccount::createMonthlyStatement()
{
	for (int i = 0; i < count; i++)
	{
		int n;
		n = bal[i];
		cout << "\n\n\n------------------";
		cout << "\nBalance : " << n;
		if (withDrawn[i] < 0)
		{
			n = withDrawn[i]*-1;
			cout << "\nDeposited : " << n;
			n = bal[i] + withDrawn[i];
			cout << "\nNew Balance : " << n;
		}
		else
		{
			cout << "\nWithdrwan : " << n;
			n = bal[i] - withDrawn[i];
			cout << "\nRemaining Balance : " << n;
		}
	}
}
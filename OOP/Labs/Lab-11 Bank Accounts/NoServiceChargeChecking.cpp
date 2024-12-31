#include"NoServiceChargeChecking.h"
NoServiceChargeChecking::NoServiceChargeChecking(String n, String a, double b, double m, double i):CheckingAccount(n,a,b)
{
	minBalance = (m >= 0 ? m : 0);
	interestRate = (i >= 0 ? i : 0);
}
void NoServiceChargeChecking::writeCheck(double amount)
{
	if ((getBalance() - amount) >= minBalance)
	{
		withDraw(amount);
	}
}
void NoServiceChargeChecking::createMonthlyStatement()
{
	for (int i = 0; i < count; i++)
	{
		int n;
		n = bal[i];
		cout << "\n\n\n------------------";
		cout << "\nBalance : " << n;
		n = withDrawn[i];
		cout << "\nWithdrwan : " << n;
		n = bal[i]-withDrawn[i];
		cout << "\nRemaining Balance : " << n;
	}
}
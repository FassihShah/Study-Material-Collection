#include"HighInterestSavings.h"
HighInterestSavings::HighInterestSavings(String n, String a, double b, double m, double i):SavingsAccount(n,a,b,i)
{
	minBalance = (m >= 0 ? m : 0);
}
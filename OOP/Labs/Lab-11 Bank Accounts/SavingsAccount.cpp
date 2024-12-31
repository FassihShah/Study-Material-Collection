#include"SavingsAccount.h"
SavingsAccount::SavingsAccount(String n, String a, double b, double i):BankAccount(n,a,b)
{
	interestRate = (i >= 0 ? i : 0);
}
void SavingsAccount::createMonthlyStatement()
{

}
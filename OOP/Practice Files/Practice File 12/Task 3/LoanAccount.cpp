#include"LoanAccount.h"
void LoanAccount::deposit(double amount)
{
	credit(amount);
}
double LoanAccount::calculateInterest(int months)
{
    if (customer == INDIVIDUAL)
    {
        if (months <= 3) 
        {
            return balance;
        }
        else 
        {
            return  balance * (1 + interestRate * (months - 3));
        }
    }
    if (months <= 2) 
    {
        return balance;
    }
    else 
    {
        return balance * (1 + interestRate * (months - 2));
    }
}
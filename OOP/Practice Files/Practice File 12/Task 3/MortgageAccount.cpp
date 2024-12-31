#include"MortgageAccount.h"
void MortgageAccount::deposit(double amount)
{
	credit(amount);
}
double MortgageAccount::calculateInterest(int months)
{
    if (customer == INDIVIDUAL)
    {
        if (months <= 6) 
        {
            return balance;
        }
        else 
        {
            return balance * (1 + interestRate * (months - 6));
        }
    }
    else 
    {
        if (months <= 12) 
        {
            return balance * (1 + (interestRate / 2) * months);
        }
        else 
        {
            return balance * (1 + interestRate * (months - 12)) + balance * (1 + (interestRate / 2) * 12);
        }
    }
}
#include"CertificateOfDeposit.h"
CertificateOfDeposit::CertificateOfDeposit(String n, String a, double b, int m, double i):BankAccount(n,a,b),maturityMonths(m)
{
	interestRate = (i >= 0 ? i : 0);
}
void CertificateOfDeposit::createMonthlyStatement()
{

}
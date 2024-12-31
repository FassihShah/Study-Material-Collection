#ifndef CERTIFICATE_OF_DEPOSIT_H
#define CERTIFICATE_OF_DEPOSIT_H
#include"BankAccount.h"
class CertificateOfDeposit :public BankAccount
{
	const int maturityMonths;
	int currMonth;
	double interestRate;
public:
	CertificateOfDeposit(String, String, double, int, double);
	void createMonthlyStatement();
};
#endif
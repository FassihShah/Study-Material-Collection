#include"ServiceChargeChecking.h"
ServiceChargeChecking::ServiceChargeChecking(String n, String a, double b, double c, double l):CheckingAccount(n,a,b),checksLimit(l)
{
	serviceCharges = (c >= 0 ? c : 0);
}
void ServiceChargeChecking::writeCheck(double amount)
{
	if (checksUsed < checksLimit)
	{
		withDraw(amount);
	}
}
void ServiceChargeChecking::createMonthlyStatement()
{

}
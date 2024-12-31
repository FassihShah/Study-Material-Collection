#ifndef HACKER_H
#define HACKER_H
#include"Customer.h"
class Hacker :public Customer
{
public:
	using Customer::Customer;
	double computeBill() override;
};
#endif
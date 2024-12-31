#ifndef HIGH_INTEREST_CHECKING_H
#define HIGH_INTEREST_CHECKING_H
#include"NoServiceChargeChecking.h"
class HighInterestChecking :public NoServiceChargeChecking
{
public:
	NoServiceChargeChecking::NoServiceChargeChecking;
};
#endif
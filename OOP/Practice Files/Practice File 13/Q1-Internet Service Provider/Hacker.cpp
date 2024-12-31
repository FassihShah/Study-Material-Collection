#include"Hacker.h"
double Hacker::computeBill()
{
	if (getSpaceUsed() > 50)
	{
		cout << "\nHacker is not valid option because used disk space is greater than 50 MB";
	}
	if (getHours() > 10)
		return (20 + ((getHours() - 10) * 2.50));
	else
		return 20;
}
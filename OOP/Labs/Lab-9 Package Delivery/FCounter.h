#ifndef FCOUNTER_H
#define FCOUNTER_H
#include"Counter.h"
class FCounter:public Counter
{
public:
	FCounter(int = 0);
	void decrement();
};



#endif
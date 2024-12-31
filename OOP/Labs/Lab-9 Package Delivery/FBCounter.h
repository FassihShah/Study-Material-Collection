#ifndef FBCOUNTER_H
#define FBCOUNTER_H
#include"Counter.h"
class FBCounter
{
	Counter c;
public:
	FBCounter(int = 0);
	void increment();
	void decrement();
	void reset();
	void startAt(int);
	int getCounterValue();
};

#endif

#ifndef ORDERED_PAIR_H
#define ORDERED_PAIR_H
#include"Set.h"
class OrderedPair
{
	int a;
	int b;
public:
	OrderedPair(int = 0, int = 0);
	int& atA();
	int& atB();
	const int& atA() const;
	const int& atB() const;
};

#endif

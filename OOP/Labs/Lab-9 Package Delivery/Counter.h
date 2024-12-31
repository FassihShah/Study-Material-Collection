#ifndef COUNTER_H
#define COUNTER_H
class Counter
{
	int value;
public:
	Counter(int = 0);
	void increment();
	void reset();
	void startAt(int);
	int getCounterValue();
};
#endif

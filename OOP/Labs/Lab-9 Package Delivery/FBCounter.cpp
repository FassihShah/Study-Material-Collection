#include"FBCounter.h"
FBCounter::FBCounter(int i) :c(i)
{

}
void FBCounter::increment()
{
	c.increment();
}
void FBCounter::decrement()
{
	c.startAt(c.getCounterValue() - 1);
}
void FBCounter::reset()
{
	c.reset();
}
void FBCounter::startAt(int i)
{
	c.startAt(i);
}
int FBCounter::getCounterValue()
{
	return c.getCounterValue();
}
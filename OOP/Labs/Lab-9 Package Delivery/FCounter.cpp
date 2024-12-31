#include"FCounter.h"
FCounter::FCounter(int i):Counter(i)
{

}
void FCounter::decrement()
{
	startAt(getCounterValue() - 1);
}
#include"ChatRoom.h"
ChatRoom::ChatRoom(String n, int d):Customer(n)
{
	noOfDials = d;
}
double ChatRoom::computeBill()
{
	return 50 + (noOfDials * 0.10);
}
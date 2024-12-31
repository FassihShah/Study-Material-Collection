#ifndef CHAT_ROOM_H
#define CHAT_ROOM_H
#include"Customer.h"
class ChatRoom:public Customer
{
	int noOfDials;
public:
	ChatRoom(String, int);
	double computeBill();
};
#endif
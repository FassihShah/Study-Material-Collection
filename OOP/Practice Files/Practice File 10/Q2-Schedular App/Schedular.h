#ifndef SCHEDULAR_H
#define SCHEDULAR_H
#include"Task.h"
class Schedular
{
	Task* taskList;
	int noOfTasks;
	int capacity;
public:
	Schedular();
	void addTask(const Task&);
	void reSize(int);
	void displayTask(const Date& = Date(1, 1, 1500)) const;
	void displayTodaysTasks() const;
	~Schedular();
	void operator =(const Schedular&);
};
#endif
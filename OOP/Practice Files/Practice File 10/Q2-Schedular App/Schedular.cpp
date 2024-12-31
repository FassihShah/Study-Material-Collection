#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include"Schedular.h"
using namespace std;
Schedular::Schedular()
{
	taskList = nullptr;
	noOfTasks = 0;
	capacity = 0;
}
void Schedular::reSize(int cap)
{
	if (cap <= 0)
	{
		taskList = nullptr;
		capacity = 0;
		noOfTasks = 0;
		return;
	}
	Task* temp = new Task[cap];
	int i;
	if (noOfTasks != 0)
	{
		for (i = 0; i < cap && i < noOfTasks; i = i + 1)
		{
			temp[i] = taskList[i];
		}
	}
	int tem = (noOfTasks > cap ? cap : noOfTasks);
	this->~Schedular();
	capacity = cap;
	taskList = temp;
	noOfTasks = tem;
}
void Schedular::addTask(const Task& t)
{
	if (capacity == noOfTasks)
	{
		reSize(capacity + 1);
	}
	taskList[noOfTasks] = t;
	noOfTasks = noOfTasks + 1;
}
void Schedular::displayTask(const Date& d) const
{
	bool status = false;
	for (int i = 0; i < noOfTasks; i = i + 1)
	{
		if (taskList[i].getDate() == d)
		{
			status = true;
			String s{ taskList[i].getMessage() };
			cout << "\nTask is : ";
			s.display();
			cout << "\nTime of task is : ";
			taskList[i].getTime().printTwelveHourFormat();
		}
	}
	if (!status)
		cout << "\nNo Task Found !";
}
void Schedular::displayTodaysTasks() const
{
	time_t current_time = time(0);
	tm* date = localtime(&current_time);
	Date d{ date->tm_mday,date->tm_mon + 1,date->tm_year + 1900 };
	displayTask(d);
}
Schedular::~Schedular()
{
	if (taskList != nullptr)
	{
		delete[]taskList;
		taskList = nullptr;
		noOfTasks = 0;
		capacity = 0;
	}
}
void Schedular::operator =(const Schedular& ref)
{
	this->~Schedular();
	if (ref.capacity == 0 || ref.noOfTasks == 0)
		return;
	reSize(ref.noOfTasks);
	for (int i = 0; i < ref.noOfTasks; i = i + 1)
	{
		taskList[i] = ref.taskList[i];
	}
}
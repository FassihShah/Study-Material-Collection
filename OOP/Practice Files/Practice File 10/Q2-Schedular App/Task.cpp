#include"Task.h"
#include<iostream>
using namespace std;
Task::Task():taskDate(1,1,2000),taskTime(1,1,1),taskMsg(String{"hello"})
{
	
}
Task::Task(const Date& d, const Time& t, const String& m):taskDate(d),taskMsg(m),taskTime(t)
{

}
void Task::updateDate(const Date& nd)
{
	taskDate = nd;
}
void Task::updateTime(const Time& nt)
{
	taskTime = nt;
}
void Task::updateMessage(const String& m)
{
	taskMsg.reSize(0);
	taskMsg.insert(0, m);
}
void Task::setTask(const Date& d, const Time& t, const String& m)
{
	updateDate(d);
	updateTime(t);
	updateMessage(m);
}
Date Task::getDate() const
{
	return taskDate;
}
Time Task::getTime() const
{
	return taskTime;
}
String Task::getMessage() const
{
	return taskMsg;
}
#ifndef TASK_H
#define TASK_H
#include"Date.h"
#include"Time.h"
class Task
{
	Date taskDate;
	Time taskTime;
	String taskMsg;
public:
	Task();
	Task(const Date& , const Time& , const String& );
	void setTask(const Date& , const Time& , const String& );
	void updateDate(const Date&);
	void updateTime(const Time&);
	void updateMessage(const String&);
	Date getDate() const;
	Time getTime() const;
	String getMessage() const;
};
#endif

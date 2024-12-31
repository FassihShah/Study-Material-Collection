#include<iostream>
#include"SchedularApp.h"
using namespace std;
void SchedularApp::startApp()
{
	Schedular s;
	int opt;
	do
	{
		cout << "\n\n\t\t\t  SCHEDULAR APP";
		cout << "\n\t\t------------------------------------------";
		cout << "\n\t\t  To add task, press  : 1";
		cout << "\n\t\t  To display any date tasks, press  : 2";
		cout << "\n\t\t  To display today tasks, press  : 3";
		cout << "\n\t\t  To close the app, press  : 0";
		cout << "\n\t\t------------------------------------------";
		cout << "\n\t\tPress : ";
		cin >> opt;
		if (opt == 1)
		{
			String msg;
			Time t;
			Date d;
			cin.ignore();
			cout << "\nEnter the message : ";
			msg.input();
			d.inputDate();
			t.inputTime();
			Task tsk{ d, t, msg };
			s.addTask(tsk);
		}
		else if (opt == 2)
		{
			Date d;
			d.inputDate();
			s.displayTask(d);
		}
		else if (opt == 3)
		{
			s.displayTodaysTasks();
		}
		else if (opt != 0)
		{
			cout << "\nInvalid option !";
		}
	} 
	while (opt != 0);
}
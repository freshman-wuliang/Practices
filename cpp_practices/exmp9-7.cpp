#include<iostream>

using namespace std;

class Time
{
	public :
		Time(int h = 0,int m = 0,int s = 0)
		:hour(h),minute(m),second(s)
		{}
		
		~Time()
		{
			cout << "destructor call" << endl;
		}
		
		void display(void);
		
		int hour;
		int minute;
		int second;
};

int main(void)
{
	Time t1(12,30,56);
	Time *ptime = &t1;
	int *ph,*pm,*ps;
	void (Time::*pf)(void);
	
	//对象名
	t1.display();
	cout << "hour:" << t1.hour << endl;
	cout << "minute:" << t1.minute << endl;
	cout << "second:" << t1.second << endl;
	
	ph = &t1.hour;
	pm = &t1.minute;
	ps = &t1.second;
	pf = &Time::display;   //不指定具体对象
	
	//对象成员指针
	cout << endl;
	(t1.*pf)();
	cout << "hour:" << *ph << endl;
	cout << "minute:" << *pm << endl;
	cout << "second:" << *ps << endl;
	
	//对象指针
	cout << endl;
	(*ptime).display();
	cout << "hour:" << (*ptime).hour << endl;
	cout << "minute:" << (*ptime).minute << endl;
	cout << "second:" << (*ptime).second << endl;
	
	return 0;
}

void Time::display(void)
{
	cout << hour << ":" << minute << ":" << second << endl;
}
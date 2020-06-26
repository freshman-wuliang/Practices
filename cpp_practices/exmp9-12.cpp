#include<iostream>

using namespace std;

class Time
{
	public :
		Time(int h=0,int m=0,int s=0)
		:hour(h),minute(m),second(s)
		{}
		
		Time(Time &t);
		
		~Time();
		
		friend void display(Time &t);
		
	private :
		int hour;
		int minute;
		int second;
};

void display(Time &t);

int main(void)
{
	Time t(12,23,45);
	
	display(t);
	
	return 0;
}

Time::Time(Time &t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}

Time::~Time()
{
	cout << "destructor call" << endl;
}

void display(Time &t)
{
	cout << t.hour << ":" << t.minute << ":" << t.second << endl;
}
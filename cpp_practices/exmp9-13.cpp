//友元成员函数

#include<iostream>

using namespace std;

class Date;   //提前引用声明

class Time
{
	public :
		Time(int h=0,int m=0,int s=0)
		:hour(h),minute(m),second(s)
		{}
		
		Time(Time &t);
		
		~Time();
		
		void display(void);
		
		void display_data(Date &d);
		
	private :
		int hour;
		int minute;
		int second;
};

class Date
{
	public :
		Date(int y=0,int m=0,int d=0)
		:year(y),month(m),day(d)
		{}
		
		Date(Date &d);
		
		~Date();
		
		void display(void);
		
		friend void Time::display_data(Date &d);
		
	private :
		int year;
		int month;
		int day;
};

int main(void)
{
	Date d(1997,4,15);
	Time t(12,12,12);
	
	d.display();
	t.display();
	t.display_data(d);
	
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
	cout << "class::Time destructor call" << endl;
}

void Time::display(void)
{
	cout << hour << ":" << minute << ":" << second << endl;
}

void Time::display_data(Date &d)
{
	cout << d.year << "-" << d.month << "-" << d.day << endl;
}

Date::Date(Date &d)
{
	year = d.year;
	month = d.month;
	day = d.day;
}

Date::~Date()
{
	cout << "class::Date destructor call" << endl;
}

void Date::display(void)
{
	cout << year << "-" << month << "-" << day << endl;
}
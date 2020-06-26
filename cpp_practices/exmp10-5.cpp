#include<iostream>

using namespace std;

class Time
{
	public:
		Time(int h=0,int m=0,int s=0)
		:hour(h),minute(m),second(s)
		{}
		
		Time(const Time &t);
		
		~Time();
		
		void display(void);
		
		void operator ++ (void);
		
		void operator ++ (int);
		
	private:
		int hour;
		int minute;
		int second;
};

int main(void)
{
	Time t(23,59,56);
	
	t.display();
	for(int i=1;i<=10;i++)
	{
		t++;
		t.display();
	}
	
	return 0;
}

Time::Time(const Time &t)
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

void Time::operator ++ (void)
{
	second++;
	if(second >= 60)
	{
		minute++;
		second -= 60;
	}
	
	if(minute >= 60)
	{
		hour++;
		minute -= 60;
	}
	
	if(hour >= 24)
		hour -= 24;
	
	//cout << "++call" << endl;
}

void Time::operator ++ (int)
{
	second++;
	if(second >= 60)
	{
		minute++;
		second -= 60;
	}
	
	if(minute >= 60)
	{
		hour++;
		minute -= 60;
	}
	
	if(hour >= 24)
		hour -= 24;
	
	//cout << "call++" << endl;
}
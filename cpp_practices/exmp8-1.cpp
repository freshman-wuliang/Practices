#include<iostream>

using namespace std;

class Time
{
	public :
		void setTime(int h,int m,int s);
		
		void displayTime(void);
		
	private :
		int hour;
		int minute;
		int second;
};

int main(void)
{
	Time t1;
	
	t1.setTime(12,25,36);
	t1.displayTime();
	
	return 0;
}

void Time::setTime(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::displayTime(void)
{
	cout << hour << ":" << minute << ":" << second << endl;
}
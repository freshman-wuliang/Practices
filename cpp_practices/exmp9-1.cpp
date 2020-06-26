#include<iostream>

using namespace std;

class Time
{
	public :
		Time();   //构造函数
		
		void setTime(int h,int m,int s);
		
		void printTime(void);
		
	private :
		int hour;
		int minute;
		int second;
};

Time::Time(){
	hour = 0;
	minute = 0;
	second = 0;
}

void Time::setTime(int h,int m,int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::printTime(void)
{
	cout << hour << ":" << minute << ":" << second << endl;
}

int main(void)
{
	Time t1;
	
	t1.setTime(12,30,56);
	t1.printTime();
	
	return 0;
}
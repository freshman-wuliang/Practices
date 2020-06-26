#include<iostream>

using namespace std;

class Box
{
	public :
		Box();   //默认构造函数
		
		Box(int h,int w,int l)   //带参数的构造函数
		:height(h),width(w),length(l)   //参数表
		{}   //没有;号
		
		int volume(void);
		
	private :
		int height;
		int width;
		int length;
};

int main(void)
{
	Box b1;
	Box b2(15,30,25);
	
	cout << "volume of b1:" << b1.volume() << endl;
	cout << "volume of b2:" << b2.volume() << endl;
	return 0;
}

Box::Box()
{
	height = 10;
	width = 10;
	length = 10;
}

int Box::volume(void)
{
	return height * width * length;
}
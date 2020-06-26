#include<iostream>

using namespace std;

class Box
{
	public :
		Box(int h,int w,int l);   //构造函数
		
		int volume(void);
		
	private :
		int height;
		int width;
		int length;
};

int main(void)
{
	Box b1(12,25,30);
	Box b2(15,30,21);
	
	cout << "volume of b1:" << b1.volume() << endl;
	cout << "volume of b2:" << b2.volume() << endl;
	
	return 0;
}

Box::Box(int h,int w,int l)
{
	height = h;
	width = w;
	length = l;
}

int Box::volume(void)
{
	return height * width * length;
}
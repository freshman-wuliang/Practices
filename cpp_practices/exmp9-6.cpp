#include<iostream>

using namespace std;

class Box
{
	public :
		Box(int h = 10,int w = 10,int l = 10)
		:height(h),width(w),length(l)
		{}
		
		~Box();
		
		int volume(void);
		
	private :
		int height;
		int width;
		int length;
};

int main(void)
{
	Box b[3] = {
		Box(10,12,15),
		Box(15,18,20),
		Box(16,20,26)
	};
	
	for(int i=1;i<=3;i++)
	{
		cout << "volume of b[" << i-1 << "] is " << b[i-1].volume() << endl;
	}
	
	return 0;
}

Box::~Box()
{
	cout << "destructor call" << endl;
}

int Box::volume(void)
{
	return height * width * length;
}
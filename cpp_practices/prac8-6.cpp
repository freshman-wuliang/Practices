#include<iostream>
#include<iomanip>

using namespace std;

class Cuboid
{
	public :
		void setCuboid(void);
		
		float cacVolume(void);
		
	private :
		float lenght;
		float width;
		float hight;
};

int main(void)
{
	Cuboid c1;
	
	c1.setCuboid();
	cout << setiosflags(ios::fixed) << setprecision(2) << c1.cacVolume() << endl;
	
	return 0;
}

void Cuboid::setCuboid(void)
{
	cout << "enter (l,w,h):";
	cin >> lenght;
	cin >> width;
	cin >> hight;
}

float Cuboid::cacVolume(void)
{
	float volume;
	
	volume = lenght * width * hight;
	
	return volume;
}